#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

// conversion from a set of characters
template <typename T>
struct cvt : public unary_function<const char*, T>
{
	T operator()(const char* s) const;
}; 

template <>
struct cvt<string> : public unary_function<const char*, string>
{
	string operator()(const char* s) const { return string(s); }
};

template <>
struct cvt<double> : public unary_function<const char*, double>
{
	double operator()(const char* s) const {  return atof(s); }
};

template <>
struct cvt<int> : public unary_function<const char*, int>
{	
	int operator()(const char* s) const { return atoi(s); }
};


template <typename T>
void ParseOptions(const char* options, const char* sep, const char* seq, 
	map<string, T>& optmap, const T& defval)
{
	if (!options)
		return;
	cvt<T> c;
	while (options[0]) {
		int eq = strcspn(options, seq);
		int cm;
		int dq = 0;
		if (options[eq] && options[eq+1]=='\"') {
	        // add support for double quotes, no single " in " " allowed
    	   // a="b=c" should return b=c for options a
			const char* p = strstr(options+eq+2, "\"");
			if (!p) return;
			if (p[1]!=seq[0] && p[1]!='\0') {
				fprintf(stderr, "invalid options %s\n", options);
				return;
			}
			cm = p + 1 - options;
			dq = 1;
		} else 
			cm = strcspn(options, sep);
		if (eq < cm) {
			string key(options, eq);
			string val(options + eq + 1 + dq, cm - eq - 1 - dq*2);
			optmap[key] = c(val.c_str());
		} else {
			string key(options, cm);
			optmap[key] = defval;
		}
		options += cm;
		options += strspn(options, sep);
	}
}


int main(int argc, char* argv[]) 
{
	/*
	if (argc < 2) {
		fprintf(stderr, "no options provided.\n");
		exit(1);
	} */
	map<string, string> options;
	const char* defopt = ",dithergray"; //argv[1];
	ParseOptions(defopt, ",", "=", options, string("1"));
	
	printf("options parsed:\n");
	map<string, string>::const_iterator it = options.begin();
	for (; it != options.end(); ++it) {
		printf("%s=>%s\n", it->first.c_str(),it->second.c_str());
	}
	return 0;
}





