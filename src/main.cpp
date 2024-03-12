
#include "rco.h"


int psp2cxml_tool(const char *src, const char *dst){

	int res;
	rco::compiler compiler;

	res = compiler.Compile(src);
	if(res < 0){
		printf("Compile 0x%X\n", res);
		return res;
	}

	res = compiler.Save(dst);
	if(res < 0){
		printf("Save 0x%X\n", res);
		return res;
	}

	return 0;
}

int main(int argc, char *argv[]){

	if(argc != 2){
		printf("usage: psp2cxml-tool ./sample_plugin.xml\n");
		return EXIT_FAILURE;
	}

	int res;
	const char *src_path;
	std::string dst_path;

	src_path = argv[1];

	const char *ext = strrchr(src_path, '.');
	if(ext != NULL && strcmp(ext, ".xml") == 0){

		size_t path_len = ext - src_path;

		char *x = (char *)malloc(path_len + 1);

		memcpy(x, src_path, path_len);
		x[path_len] = 0;

		dst_path = x;

		free(x);
	}else{
		dst_path = src_path;
	}

	dst_path += ".rco";

	res = psp2cxml_tool(src_path, dst_path.c_str());
	if(res < 0){
		printf("psp2cxml_tool 0x%X\n", res);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
