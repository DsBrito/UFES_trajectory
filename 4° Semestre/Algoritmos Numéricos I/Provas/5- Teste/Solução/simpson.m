
function I=simpson(f,a,b,N)

%f=@(x)sqrt(x);
%a=1;
%b=3;
%N=10;
h=(b-a)/N;
s=f(a)+f(b);

for k=1:2:(N-1)
   x=a+h*k;
   s=s+4*f(x);
end

for k=2:2:(N-2)
   x=a+h*k;
   s=s+2*f(x);
end

I=(h*s)/3;


