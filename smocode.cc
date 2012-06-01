static int remove_subdirectory(const char* dir)
{
	DIR* dirp;
	struct dirent* dp;
	struct stat stb;
	char path[1024];
	
	dirp = opendir(dir);
	if (!dirp) 
		return 0;
	while ((dp=readdir(dirp))!=NULL) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;	// skip "." and ".."
		snprintf(path, sizeof path, "%s/%s", dir, dp->d_name);

		if (stat(path, &stb) < 0)
			continue;
		if (S_ISDIR(stb.st_mode)) {
			if (unlink(path)<0)
					remove_directory(path);
		}
	}
	close(dirp);
	return 0;
}

SmoApp::SmoApp(int argc, char** argv)
	: StageHostLeafApp(argc, argv, "smo"), HostLeafTaskMan(),
	d_context(0), d_execWorker(0)
{
	if (d_mode==MODE_QUERY)
		return;
	RegisterTag(COMM_TAG_SMO_TASK);
	if (argv >= 2)
		d_script = argv[1];
	if (d_dbjob >= 0) {
		char path[1024];
		snprintf(path, sizeof path, RESULTDIR, "job%d",
				GetDatabase(), d_dbjob);
		d_resultdir = path;
		snprintf(path, sizeof path, WORKDIR "job%d",
				GetDatabase(), d_dbjob);
		if (d_workdir==path &&(d_mode==MODE_HOST||d_mode==MODE_SA||
					(d_mode==MODE_LEAF&&d_idx<0 && IsStandAlone())))
			remove_subdirectory(d_workdir.c_str());
	}
}

static bool symlink_dir(const char* olddir, const char* newdir, int silent=0)
{
	if (create_directory(newdir)<0) return false;
	char oldpath[1024], newpath[1024];
	DIR* dirp;
	struct dirent* dp;
	dirp = opendir(olddir);
	if (!dirp) {
		log_printf(LOG_USER, "Can not open dir %s\n", olddir);
		return false;
	}
	while ((dp = readdir(dirp))!=NULL) {
		if (!strcmp(dp->d_name, ".")|| !strcmp(dp->d_name, ".."))
			continue;
		snprintf(oldpath, sizeof oldpath, "%s/%s", olddir, dp->d_name);
		snprintf(newpath, sizeof newpath, "%s/%s", newdir, dp->d_name);
		if (symlink(oldpath, newpath)<0 && !silent) {
			log_printf(LOG_USER, "Can not symlink %s to %s\n", oldpath, newpath);
			return false;
		}
	}
	closedir(dirp);
	return true;
}


