%{
int count=0;
int key=0;
int idd=0;
int oop=0;
int pun=0;
int digi=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
letter[a-zA-Z]
digit [0-9]
op[+-//*=]
punc[;,]
keyword[int float double long string void]
%%
#.* {printf("\n%s is a preprocessor directive  {Token No- %d}",yytext,++count);}
{keyword} printf("{keyword %s } \t\t {Token No- %d} \t {Keyword No- %d}\n",yytext,++count,++key);
{letter}({letter}|{digit})* printf("{id %s } \t\t {Token NO- %d} \t {Identifier No- %d}\n",yytext,++count,++idd);
{op} printf("{op %s } \t\t {Token No-%d} \t\t {operator No- %d}\n",yytext,++count,++oop);
{punc} printf("{punctuation %s } \t {Token No- %d}  \t {Punctuation No- %d}\n",yytext,++count,++pun);
{digit} printf("{Num %s } \t\t {Token No- %d} \t {digit No- %d}\n",yytext,++count,++digi);
%%

int main(int argc, char **argv)
{
FILE *file;
file=fopen("var.c","r");
if(!file)
{
printf("could not open the file");
exit(0);
}
yyin=file;
yylex();
printf("\n");
return(0);
}

int yywrap()
{
return(1);
}
