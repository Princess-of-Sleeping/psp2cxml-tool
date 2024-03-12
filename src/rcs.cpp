
#include "cxml/cxml.h"
#include "rcs.h"


rcs::compiler::compiler(){
	SetMagic("RCSF");
	SetVersion(CXML_VERSION(1, 1, 0));

	append_schema({
		"stringset",
		cxml::schema::item::NoneParent,
		{
		}
	});

	append_schema({
		"string",
		{"stringset"},
		{
			{"src", cxml::attr_type_wstring},
			{"id",  cxml::attr_type_idhash}
		}
	});
}
