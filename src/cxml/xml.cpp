
#include "tinyxml2.h"
#include "xml.h"


int ProcessXml(tinyxml2::XMLDocument *doc, XmlProcessCallback callback, void *argp){

	int res;
	tinyxml2::XMLElement *tag;

	tag = doc->FirstChildElement();

	while((uintptr_t)tag != (uintptr_t)doc){

		res = callback(doc, tag, argp);
		if(res < 0){
			return res;
		}

		if(tag->FirstChildElement() != NULL){
			tag = tag->FirstChildElement();

		}else if(tag->NextSiblingElement() != NULL){
			tag = tag->NextSiblingElement();

		}else{
			while(tag->NextSiblingElement() == NULL){
				if(doc == tag->Parent()){
					return 0;
				}

				tag = tag->Parent()->ToElement();
			}

			if((uintptr_t)tag != (uintptr_t)doc){
				tag = tag->NextSiblingElement();
			}
		}

		if(tag == NULL){
			tag = (tinyxml2::XMLElement *)doc;
		}
	}

	return -1;
}
