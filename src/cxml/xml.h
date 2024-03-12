
#ifndef _XML_H_
#define _XML_H_

#include "tinyxml2.h"

typedef int (* XmlProcessCallback)(tinyxml2::XMLDocument *doc, tinyxml2::XMLElement *tag, void *argp);

int ProcessXml(tinyxml2::XMLDocument *doc, XmlProcessCallback callback, void *argp);


#endif /* _XML_H_ */
