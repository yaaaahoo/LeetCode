// 
/*
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            vector<string> path;
    
            backtracing(0,s,path,res);
            return res;
        }
    
        void backtracing(int start, string& s, vector<string>& path, vector<string>& res)
        {
            if(path.size()==4&&start>=s.size())
            {
                string ip="";
                for(auto& str:path)
                    ip=ip+str+'.';
    
                ip.pop_back();
                res.emplace_back(ip);
                return;
            }
            
            for(int i=start;i<s.size();++i)
            {
                string sub_str=s.substr(start,i-start+1);
                if((sub_str.size()>1&&sub_str[0]=='0')||stoi(sub_str)>255) return;
    
    
                path.emplace_back(sub_str);
                backtracing(i+1, s, path, res);
                path.pop_back();
            }
        }
    };