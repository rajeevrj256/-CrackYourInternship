class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int index=0;
       int rem_petrol=0;
       int totat_petrol=0;
       for(int i=0;i<n;i++){
           rem_petrol+=p[i].petrol-p[i].distance;
           
           if(rem_petrol<0){
               index=i+1;
               totat_petrol+=rem_petrol;
               rem_petrol=0;
           }
       }
       if(rem_petrol+totat_petrol>=0)return index;
       else return -1;
    }
};