class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int verticalMdiff = 0;
        int index = 0;
        int Ans = 0;
        verticalCuts.push_back(w);
        horizontalCuts.push_back(h);
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        int VCsize = verticalCuts.size();
        int HCsize = horizontalCuts.size();
        int LastCut = 0; 
        for(int i = 0 ; i  < VCsize; i++){
            if((verticalCuts[i] - LastCut) > verticalMdiff){
                index = i;
                verticalMdiff = (verticalCuts[i] - LastCut);
            }
            LastCut =  verticalCuts[i];
        }
        
        int Max_Width = 0;
        if(index == 0)
         Max_Width = (verticalCuts[index]);
        else
         Max_Width = (verticalCuts[index] - verticalCuts[index -1]);   
        
        cout<<Max_Width<<endl;
        LastCut = 0;
        int Max_H  = 0;
        for(int   i = 0 ; i < HCsize; i ++){
           //  long long Curr_Height = (long long)(horizontalCuts[i] - LastCut);
           //cout<<Curr_Height<<endl;
            Max_H = max(Max_H,(horizontalCuts[i] - LastCut));
            LastCut = horizontalCuts[i];
        }
        
        //cout<<"*************************************"<<endl;
        
        return (1LL*Max_H*Max_Width) % 1000000007;
        
		// horizontalCuts.push_back(h);
		// sort(horizontalCuts.begin(), horizontalCuts.end());
		// int maxh = horizontalCuts[0];
		// for(int i=1; i<horizontalCuts.size(); i++){
		// maxh = max(maxh, horizontalCuts[i] - horizontalCuts[i-1]);
		// }
		// cout<<"horizoantal_cuts : "<<maxh<<endl;
		// verticalCuts.push_back(w);
		// sort(verticalCuts.begin(), verticalCuts.end());
		// int maxv = verticalCuts[0];
		// for(int i=1; i<verticalCuts.size(); i++){
		// maxv = max(maxv, verticalCuts[i] - verticalCuts[i-1]);
		// }
		// cout<<"vertical _cuts : "<<max<<endl;
		// return (1LL*maxh*maxv) % 1000000007;
        
    }
};