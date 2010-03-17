
The original values will commented out
first argument inside ${}
multi = multiple values field
single = single value field
choice = list of choices
2 = 2 value field
NONE = no default value
RANDOM = generate some value
TYPE = some of values UUID, int, string, ip, bool   


ini files:
${m key=defaultvalue1,...,defaultvalueN|Type|optional description text}
${s key=defaultvalue|Type|optional description text}

xml files:
${mkey=defaultvalue1,...,defaultvalueN|Type|optional description text}
${s key=defaultvalue|Type|optional description text}1


${s RegionUUID=RANDOM|UUID}            
generates => RegionUUID=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx