%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n%s is a preprocessor directive",yytext);}
int | 
float |
char |
double |
while |
for |
struct |
typedef |
do |
if |
break |
continue |
void |
switch |
return |
else |
goto {printf("%s is a keyword \n\t",yytext);}
"/*" {COMMENT=1;}{printf(" %s is a COMMENT \n\t",yytext);}
{identifier}\( {if(!COMMENT)printf("FUNCTION \t%s \n",yytext);}
\{  {if(!COMMENT)printf("BLOCK BEGINS \n\t");}
\}  {if(!COMMENT)printf("BLOCK ENDS ");}
{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("%s IDENTIFIER \n\t",yytext);}
\".*\" {if(!COMMENT)printf("%s is a STRING \n\t",yytext);}
[0-9]+ {if(!COMMENT) printf("%s is a NUMBER \n\t",yytext);}
\)(\:)? {if(!COMMENT)ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT)printf("%s is an ASSIGNMENT OPERATOR \n\t",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("%s is a RELATIONAL OPERATOR\n\t",yytext);}
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
