#include "./functions.c"

Comment getComment(void)
{
	Comment temp;

	temp.author = "toto";
	temp.content = "hello, j'ai écrit un commentaire";
	temp.created_at = getCurrentTime();
	temp.id = 0;
	temp.likeCount = 34;

	return temp;
}
