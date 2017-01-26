#ifndef _TEXT_RESOLVER_H_
#define _TEXT_RESOLVER_H_

/***
Class utilitaire qui traduit les ID & booléens en texte lisible par les humains
***/
class TextResolver
{
public:
	static char * typeToName(int type);
	static char * boolToFrench(bool value);

};

#endif // _TEXT_RESOLVER_H_
