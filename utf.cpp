#include <iostream>
#include <fstream>
using namespace std;

ofstream fout ("386intel fixed.txt");
int convert (string unicode);
void output (int utf);
ifstream fin("386intel.txt");
int main()
{
  string A[255];
A[128]="C7";
A[129]="FC";
A[130]="E9";
A[131]="E2";
A[132]="E4";
A[133]="E0";
A[134]="E5";
A[135]="E7";
A[136]="EA";
A[137]="EB";
A[138]="E8";
A[139]="EF";
A[140]="EE";
A[141]="EC";
A[142]="C4";
A[143]="C5";
A[144]="C9";
A[145]="E6";
A[146]="C6";
A[147]="F4";
A[148]="F6";
A[149]="F2";
A[150]="FB";
A[151]="F9";
A[152]="FF";
A[153]="D6";
A[154]="DC";
A[155]="A2";
A[156]="A3";
A[157]="A5";
A[158]="20A7";
A[169]="2310";
A[170]="AC";
A[171]="BD";
A[172]="BC";
A[173]="A1";
A[174]="AB";
A[178]="BB";
A[176]="2591";
A[177]="2592";
A[178]="2593";
A[179]="2502";
A[180]="2524";
A[181]="2561";
A[182]="2552";
A[183]="2556";
A[184]="2555";
A[185]="2563";
A[186]="2551";
A[187]="2557";
A[188]="255D";
A[189]="255C";
A[190]="255B";
A[191]="2510";
A[192]="2514";
A[193]="2534";
A[194]="252C";
A[195]="251C";
A[196]="2500";
A[197]="253C";
A[198]="255E";
A[199]="255F";
A[200]="255A";
A[201]="2554";
A[202]="2569";
A[203]="2566";
A[204]="2560";
A[205]="2550";
A[206]="256C";
A[207]="2567";
A[208]="2568";
A[209]="2564";
A[210]="2565";
A[211]="2559";
A[212]="2558";
A[213]="2552";
A[214]="2553";
A[215]="256B";
A[216]="256A";
A[217]="2518";
A[218]="250C";
A[219]="2588";
A[220]="2584";
A[221]="258C";
A[222]="2590";
A[223]="2580";
A[224]="3B1";
A[225]="DF";
A[226]="393";
A[227]="3C0";
A[228]="3A3";
A[229]="3C3";
A[230]="B5";
A[231]="3C4";
A[232]="3A6";
A[233]="398";
A[234]="3A9";
A[235]="3B4";
A[236]="221E";
A[237]="03C6";
A[238]="03B5";
A[239]="2229";
A[240]="2261";
A[241]="B1";
A[242]="2265";
A[243]="2264";
A[244]="2320";
A[245]="2321";
A[246]="F7";
A[247]="2248";
A[248]="B0";
A[249]="2219";
A[250]="B9";
A[251]="221A";
A[252]="207F";
A[253]="B2";
A[254]="25A0";


  int utf, byte[5], q=0, i, charnum;
  unsigned char dec;
  string line;
  unsigned char a[2]={0x00, 0x00};
  unsigned char b[3]={0x00, 0x00, 0x00};
  unsigned char c[4]={0x00, 0x00, 0x00, 0x00};
  while(!fin.eof())
  {
	getline (fin, line);
  	for(i=0; i < line.length(); i++)
  	{
  		
  		dec=line[i];
  		charnum= (int) dec;
  		if(charnum < 127)
  			fout<<dec;
  		else 
		
  		{
  			q=0;
  			utf=convert(A[charnum]);
//  			cout<<hex<<utf<<endl;
  			while(utf>0)
  			{
    			byte[q]=utf%256;
			    utf/=256;
//    			cout<<hex<<byte[q]<<endl;
    			q++;
			}
			if(q==2)
  			{
	  			a[0]=byte[1], a[1]=byte[0];
	  			fout<<a;
			}
			if(q==3)
			{
				b[0]=byte[2]; b[1]=byte[1]; b[2]=byte[0];
				fout<<b;
			}
			if(q==4)
			{
				c[0]=byte[3]; c[1]=byte[2]; c[2]=byte[1]; c[3]=byte[0];
				fout<<c;
			}
  		}
  	}
  	fout<<endl;
  }
  	
  	
  
  
//  cout<<hex<<utf<<endl<<endl;
 
  	
	
}
int convert (string unicode)
{
	string binhex [16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
	char hexbin [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C', 'D', 'E', 'F'};
	string utfbin, utfhex, halfbyte;
	string bin;
  int hex = stoi (unicode, nullptr, 16);
  int i, j;
	if(hex>0x007F)
  	utfbin="110xxxxx10xxxxxx";
	if(hex>0x07FF)
	  utfbin="1110xxxx10xxxxxx10xxxxxx";
	if(hex>0xFFFF)
	  utfbin="11110xxx10xxxxxx10xxxxxx10xxxxxx";

	for(int i=0; i<unicode.length(); i++)
    for(int j=0; j<15; j++)
      if(hexbin[j] == unicode[i])
      {
		    bin.append ( binhex[j] );
        break;
      }
//      cout<<bin<<endl<<utfbin<<endl;
	j=bin.length()-1;
	for(i=utfbin.length()-1; i>=0; i--)
	{
//    cout<<i<<" ";
		while((utfbin[i]!='x')&&(i>0))
			i--;
		if((j>=0)&&(utfbin[i]=='x'))
		{
			utfbin[i]=bin[j];
			j--;
		}
		else
    if(utfbin[i]=='x')
     utfbin[i]='0';	
	}
//	cout<<endl<<utfbin<<endl;
  for(i=0; i<utfbin.length()-1; i+=4)
  {
    halfbyte.assign (utfbin, i, 4);
    for(j=0; j<15; j++)
      if(binhex[j]==halfbyte)
      {
        utfhex+=hexbin[j];
        break;
      }
  }
  return stoi(utfhex, nullptr, 16);
}


