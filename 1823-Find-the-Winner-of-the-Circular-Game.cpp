class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n=s.length();
        vector<string>s1;
        vector<string>s2;

        int count1=0,count2=0;

        for(int i=0;i<n/2;i++){
            s1.push_back(s[i]);
            
        }

         for(int i=n/2;i<n;i++){
            s2.push_back(s[i]);
        }

        for(int i=0;i<n/2;i++){
            if(s1[i]=='a','e','i','o','u','A','E','I','O','U'){
                count1++;
            }
        }
        for(int i=0;i<n/2;i++){
            if(s2[i]=='a','e','i','o','u','A','E','I','O','U'){
                count2++;
            }
        }

        if(count1==count2){
            return true;
        }

        return false;
    }
};