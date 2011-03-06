import microbe, re



cppRules = {}
cppRules["Line over 80 char"] = re.compile('[^\n]{81,}')
cppRules["Spaces instead of tabs"] = re.compile('   ')
cppRules["Missing space after control statement"] \
    = re.compile('(for|if|while|switch)\(')
cppRules["Missing space at comment start"] = re.compile('//\w')
cppRules["Missing space after operator"] \
    = re.compile('\w(==|[,=>/+\-*;\|])\w')
cppRules["Operator at line end"] = re.compile('([*=/+\-\|\&\?]|\&&|\|\|)(?=\n)')
cppRules["Missing space"] = re.compile('\){')
cppRules["Mixed tabs/spaces"] = re.compile('( \t]|\t )+')
cppRules["Malformed else"] = re.compile('}[ \t]*\n[ \t]*else')
cppRules["Lines between functions > 2"] \
    = re.compile('(?<=\n})([ \t]*\n){3,}(?=\n)')
cppRules["Lines between functions < 2"] \
    = re.compile('(?<=\n})([ \t]*\n){0,2}(?=.)')
cppRules["Windows Line Ending"] = re.compile('\r')
cppRules["Bad pointer/reference style"] \
    = re.compile('(?<=\w) [*&](?=(\w|[,\)]))')

# TODO: ignore some rules in comments
#cppRules["-Comment 1"] = re.compile('[^/]/\*(.|[\r\n])*?\*/')
#cppRules["-Comment 2"] = re.compile('(//)[^\n]*')

def func0(a):	
	print "python '" + a + "'"	
	print microbe.select(7, 12);
	return "yes"
	
def func00(text):
    regexp = re.compile('[^/]/\*(.|[\r\n])*?\*/')
    matches = regexp.finditer(text)
    for match in matches:
        microbe.select(match.start(), match.end())
        print "match", match.start(), match.end()
        
    return "ok"
    
def func1(text):
    for name, regexp in cppRules.items():                
        matches = regexp.finditer(text)
        for match in matches:
            microbe.select(match.start(), match.end())
            #print "match", match.start(), match.end()
        
    return "ok"    
    

