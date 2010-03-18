
TAIGA CONFIG CREATOR
====================
This software was developed by Jonne Nauha (jonne.nauha@evocatici.com).
Don't modify the files in templates folder or the parsing and creating of config files with your settings might fail.

TEMPLATE CONFIGS TAG DESCRIPTION
================================

The original values will commented out
first argument inside ${}$
multi = multiple values field
single = single value field
choice = list of choices
2 = 2 value field
NONE = no default value
RANDOM = generate some value
TYPE = some of values UUID, int, string, ip, bool   

ini files:
${m key=defaultvalue1,...,defaultvalueN|Type|optional description text}$
${s key=defaultvalue|Type|optional description text}$

xml files:
${mkey=defaultvalue1,...,defaultvalueN|Type|optional description text}$
${s key=defaultvalue|Type|optional description text}$

${s RegionUUID=RANDOM|UUID}$          
generates => RegionUUID=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx

Tags and template configs created by Matti Reijonen, we will update the templates as needed with new Taiga releases.

CONTACT
========
http://www.realxtend.org/
http://wiki.realxtend.org/

#realxtend-dev @ freenode