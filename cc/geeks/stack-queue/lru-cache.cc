// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{

private:
int cap;
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity)
    {
        // constructor for cache
        cap = capacity;
    }

    int get(int key)
    {
        // this function should return value corresponding to key
        if(mp.find(key) == mp.end())
          return -1;

        auto it = mp[key];
        int val = (*it).second;
        l.erase(it);
        l.push_front({key, val});
        mp[key] = l.begin();
        return val;
    }

    void set(int key, int value)
    {
        // storing key, value pair
        if(l.size() < cap){
           if(mp.find(key) != mp.end())
               l.erase(mp[key]);

          l.push_front({key, value});
          mp[key] = l.begin();
          return;
        }
        //key found
        if(mp.find(key) != mp.end()){
            l.erase(mp[key]);
        }
        else{ //erase last
            auto it = l.end();
            it--;
            mp.erase((*it).first);
            l.erase(it);
        }

        l.push_front({key, value});
        mp[key] = l.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
