#include<stdio.h>
#include<string.h>
#include<libxml/parser.h>
#include<libxml/tree.h>

//using namespace std;

xmlDocPtr doc = NULL;//указатель на документ

void rec(xmlNodePtr node)
{
	xmlNodePtr cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE) //проверяем что попали на узел
		{
			printf("node: %s\n", cur_node->name);
		}
		rec(cur_node->children);
		cur_node = cur_node->next;
	}
}

int main()
{
	LIBXML_TEST_VERSION;
	doc = xmlReadFile("test.xml", NULL,0);
	if (doc == NULL)
	{
		printf("Error parsing file \n");
		exit(1);
	}
	xmlNodePtr root = xmlDocGetRootElement(doc);
	rec(root);
	xmlFreeDoc(doc);
	return 0;
}