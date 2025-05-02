int main(int argc,char**argv,char**envp){int i;for(i=0;envp[i]!=0;i++)printf("%p => %s\n",envp[i],envp[i]);}
