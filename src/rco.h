
#ifndef _RCO_H_
#define _RCO_H_

#include "cxml/cxml.h"


class rco {
public:
	class compiler : public cxml::compiler {
	public:
		compiler();
		~compiler(){
		}

		int Compile(const char *xml_path);

	private:
		static int rco_fileProvider_default(tinyxml2::XMLElement *tag, const char *path, cxml::stack& fileimage, void *argp);
	};
};


#endif /* _RCO_H_ */
