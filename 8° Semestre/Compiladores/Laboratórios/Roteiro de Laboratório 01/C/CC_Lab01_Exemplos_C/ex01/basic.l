%%
a           { ECHO; printf(" -> Rule 1\n"); }
ab          { ECHO; printf(" -> Rule 2\n"); }
a*b+        { ECHO; printf(" -> Rule 3\n"); }
(a|b)*abb   { ECHO; printf(" -> Rule 4\n"); }
.*          { ECHO; printf(" -> Not recognised!\n"); }
\n          { printf("Next input please => "); }
%%
