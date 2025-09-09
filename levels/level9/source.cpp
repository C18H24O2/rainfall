#include <cstring>
#include <cstdlib>

class N
{
	public:
    	N(int x) : number(x) {}
	    void setAnnotation(char *str) 
		{
			int n = strlen(str);
			memcpy(annotation, str, n);
		}
    	virtual int operator+(N &r) 
		{
			return number + r.number;
		}
    	virtual int operator-(N &r) 
		{
			return number - r.number;
		}

	private:
		char annotation[100];
	    int number;
};
 
int main(int argc, char **argv)
{
    if(argc < 2) 
		exit(1);
 
    N *x = new N(5);
    N *y = new N(6);
 
    x->setAnnotation(argv[1]);
 
    return *x + *y;
}
