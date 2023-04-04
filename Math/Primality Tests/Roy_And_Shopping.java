import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class Roy_and_shopping {
 
 public static void main(String[] args) throws NumberFormatException, IOException {
  BufferedReader br=new BufferedReader(new InputStreamReader(System.in)); 
  StringBuilder ans=new StringBuilder();
  int N=Integer.parseInt(br.readLine().trim());
  int prime[]=new int[1000001];
  for(int i=0;i<prime.length;i++)
  {
   prime[i]=i;
  }
 prime[0]=prime[1]=1;
  for(int i=2;i<=1000000;i++)
  {
   if(prime[i]==i)
   {
    for(int j=i;j<1000001;j+=i)
    {
     if(prime[j]==j)
     prime[j]=i;
    }
   }
  }
  while(N-->0)
  {
   int num=Integer.parseInt(br.readLine().trim());
   int left=num-prime[num];
   ans.append(left+"\n");
   
  }
  System.out.println(ans);
 }
 
}