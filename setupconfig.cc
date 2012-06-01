void SmoApp::SetupConfig()
{
	if (!d_config.Load(d_script.c_str()))
		Fatal("Failed to load configuration file %s\n", d_script.c_str());
	d_config.SetEnv("file", d_script.c_str());
	
	const Config initcf = d_config.GetNode("SMO.init");
	if (initcf && (IsModeSH() || d_mode==MODE_LEAF)) {
		const char* command = initcf.GetConfigData("command", (const char*)0);
		if (!command) 
			Fatal("no init command specified");
		const char* xmlf = initcf.GetConfigData("xml", (const char*)0);
		if (!xmlf)
			Fatal("No init xml file name");
		FileCache* fc = d_mode==MODE_SA ? 0 : GetFileCache();
		std::string key = GetWorkDir()+"/"+xmlf;
		if (IsModeSH()) {
			CreateDualityFile(xmlf);
			const char* resultdir = "initresult";
			CreateDualityDir(resultdir);
			const char* workdir = "initwork";
			create_directory(workdir);
			clean_directory(workdir);
			int status = ExecCommand(command, d_script.c_str(), 0, -1, workdir, "init");
			if (status) 
				Fatal("Init command failed(status = 0x%x)", status);
			if (fc) {
				std::map<std::string, std::string> files;
				files[key] = d_resultdir + "/" + xmlf;
				DistributeFiles(files);
			}
		}
		if (fc) {
			FileCacheEntry* fce = fc->Lookup(key.c_str(), false);
			if (fce) 
				key = fce->GetFilePath();
		}
		xmlf = key.c_str();
		if (!d_config.Load(xmlf)
			Fatal("Failed to load post-init xml file %s", xmlf);
		d_config.SetEnv("file", xmlf);
		d_config.SetEnv("dir", GetWorkDir().c_str());
	}
	const Config cf = d_config.GetNode("App");
	if (!!cf) {
		const char* options = cf.GetConfigData("options", (const char*)0);
		if (options) {
			ParseOptions(options, ",", "=", d_options, std::string("1"));
		}
	}
	if (!GetOption("maxarea"))
		d_options["maxarea"] = "3072x3072";
	if (d_dbjob < 0) {
		const char* wisdom = cf.GetConfigData("wisdom", "wisdom");
		if (wisdom) {
			d_wisdomf = wisdom;
			LoadWisdom();
		}
	}
	std::vector<std::string> keys;
	d_config.GetConfigKeys("SMO", keys);
	Config smocf = d_config.GetNode("SMO");
	std::map<std::string, std::string> cfgkeys;
	for (unsigned int j = 0; j < keys.size(); j++) {
		const char* key = keys[j].c_str();
		for (unsigned int k = 0; ; k++) {
			Config cf = smocf.GetNode(key, k);
			if (!cf) 
				break;
			int enable = cf.GetConfigData("enable", 0);
			if (enable) {
				std::ostringstream oss;
				oss << key << '[' << k << ']';
				std::string cfgkey = oss.str();
				oss.str("");
				oss << key << enable;
				std::string stgkey = oss.str();
				cfgkeys[stgkey] = cfgkey;
			}
		}
	}
	for (std::map<std::string, std::string>::const_iterator it = d_options.begin();
		it != d_options.end(); ++it) {
		if (it->first.compare(0, 4, "SMO.")!=0)
			continue;
		std::string key = it->first;
		std::string::size_type n = key.substr(4).find('.');
		std::string k = key.substr(4, n);
		if (cfgkeys.find(k)!=cfgkeys.end())
			key.replace(4, n, cfgkeys[k]);
		log_printf(LOG_DEVELOPER, "XML override %s = %s \n",
			key.c_str(), it->second.c_str());
		d_config.SetConfigData(key, it->second);
	}
	std::list<std::pair<int, int> > enablelist;
	if (const char* elist = GetOption("enable", (const char*)0))
		parse_range_list(elist, enablelist);
	for (unsigned int j = 0; j < keys.size(); j++) {
		const char* key = keys[j].c_str();
		for (unsigned int k = 0; ; k++) {
			Config cf = smocf.GetNode(key, k);
			if (!cf) 
				break;
			int enable = cf.GetConfigData("enable", 0);
			if (!enable || !in_range(enablelist, enable, enable))
				continue;
			if (!d_stages.insert(std::make_pair(enable, std::make_pair(key, k))).second)
				Fatal("Mutiple stages at enable %d", enable);
			if (!SMO::lookupHandle(key))
				Fatal("Unknown stage %s%d", key, enable);
		}
	}
	std::string stagelist = "Enabled Stages: ";
	std::map<int, std::pair<std::string, int> >::const_iterator it;
	for (it = d_stages.begin(); it != d_stages.end(); ++it) {
		int enable = it->first;
		const char* key = it->second.first.c_str();
		char buf[256];
		snprintf(buf, sizeof buf, " %s%d",key, enable);
		stagelist += buf;
	}
	log_printf(LOG_DEVELOPER, "%s\n", stagelist.c_str());
	srand48(time(0));
	d_context = new Context(smocf);
}
