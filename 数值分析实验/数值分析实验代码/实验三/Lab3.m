% https://wenku.baidu.com/view/4f937ab1b9d528ea80c7790b.html


%复合梯形公式
function y=fx(x)  
y=sin(x)./x; 
 
 
function T_n=fht(a,b,n)
h=(b-a)/n;  
for k=0:n      
    x(k+1)=a+k*h;          
if x(k+1)==0                   
    x(k+1)=10^(-10);          
end 
end 
T_1=h/2*(fx(x(1))+fx(x(n+1)));  
for i=2:n       
    F(i)=h*fx(x(i));  
end 
T_2=sum(F);  
T_n=T_1+T_2;
 
 
 
% 复合辛普森公式
function y=f(x)  
y=sin(x)./x;  
 
 
function S_n=S_P_S(a,b,n)  
h=(b-a)/n; for k=0:n      
    x(k+1)=a+k*h;       
    x_k(k+1)=x(k+1)+1/2*h;      
    if (x(k+1)==0)|(x_k(k+1)==0)                  
    x(k+1)=10^(-10);                  
    x_k(k+1)=10^(-10);      
end 
end 
 
S_1=h/6*(f(x(1))+f(x(n+1))); 
for i=2:n       
     F_1(i)=h/3*f(x(i));  
end 
for j=1:n       
     F_2(j)=2*h/3*f(x_k(j));  
end 
S_2=sum(F_1)+sum(F_2);  
S_n=S_1+S_2;



%积分函数
function y=f(x)   
y=sin(x); 

end


% 1.复化梯形求积公式的代码
function Tn=Tn(a,b,n)  
    format long  
    h=(b-a)/n;  
    sum=0;  
    for k=1:n-1  
        sum=sum+f(a+k.*h);  
    end  
    Tn=(f(a)+2*sum+f(b))*h/2;  
end  
  
% 2.复化Simpson公式的代码

function Sn = Sn(a,b,n)
    format long
    h = (b-a)/n;
    sum1 = 0;
    sum2 = 0;
    for i = 0:n-1
        sum1 = sum1 + f(a+(i+1/2).*h);
    end
    for j = 1:n-1
        sum2 = sum2 + f(a+j.*h);
    end
    Sn = h/6*(f(a)+4*sum1+2*sum2+f(b));
end
    
% 3.复化Cotes公式的代码    
function Cn = Cn(a,b,n)  
    format long  
    h = (b-a)/n;  
    sum1 = 0;  
    sum2 = 0;  
    for i = 0:n-1  
        sum1 = sum1 + 32*f(a+(i+1/4).*h)+12*f(a+(i+1/2).*h)+32*f(a+(i+3/4).*h);  
    end  
    for j = 1:n-1  
        sum2 = sum2 + 14*f(a+j.*h);  
    end  
Cn = h/90*(7*f(a)+sum1+sum2+7*f(b));     
end


syms a1 a2 a3 a4 a5
x=[5.764 6.286 6.759 7.168 7.408];
y=[0.648 1.202 1.823 2.526 7.408];

for i=1:5
    fx=a1*x(i).^2+2*a2*x(i)*y(i)+a3*y(i).^2+2*a4*x(i)+2*a5*y(i)+1;
    vpa(fx,4);
    disp(fx);
end



f1=[

(2337909764460479*a1)/70368744177664 + (116721*a2)/15625 + (6561*a3)/15625 + (1441*a4)/125 + (162*a5)/125 + 1
 
(5561072404424805*a1)/140737488355328 + (1888943*a2)/125000 + (3253409378011701*a3)/2251799813685248 + (3143*a4)/250 + (601*a5)/250 + 1
 
(3214731408880681*a1)/70368744177664 + (12321657*a2)/500000 + (7483471623014781*a3)/2251799813685248 + (6759*a4)/500 + (1823*a5)/500 + 1
 
(7231123676894145*a1)/140737488355328 + (565824*a2)/15625 + (3592001256996483*a3)/562949953421312 + (1792*a4)/125 + (1263*a5)/250 + 1
 
(482716074259893*a1)/8796093022208 + (1714952*a2)/15625 + (482716074259893*a3)/8796093022208 + (1852*a4)/125 + (1852*a5)/125 + 1];

 

%Matlab2012b以后的版本才有的函数
[A b]=equationsToMatrix(f1,[a1 a2 a3 a4 a5]);



syms a1 a2 a3 a4 a5
[m1,m2,m3,m4,m5]=solve('(2337909764460479*a1)/70368744177664 + (116721*a2)/15625 + (6561*a3)/15625 + (1441*a4)/125 + (162*a5)/125 + 1', ...
'(5561072404424805*a1)/140737488355328 + (1888943*a2)/125000 + (3253409378011701*a3)/2251799813685248 + (3143*a4)/250 + (601*a5)/250 + 1',...
'(3214731408880681*a1)/70368744177664 + (12321657*a2)/500000 + (7483471623014781*a3)/2251799813685248 + (6759*a4)/500 + (1823*a5)/500 + 1',...
'(7231123676894145*a1)/140737488355328 + (565824*a2)/15625 + (3592001256996483*a3)/562949953421312 + (1792*a4)/125 + (1263*a5)/250 + 1',...
'(482716074259893*a1)/8796093022208 + (1714952*a2)/15625 + (482716074259893*a3)/8796093022208 + (1852*a4)/125 + (1852*a5)/125 + 1];',...
'a1','a2','a3','a4','a5')















