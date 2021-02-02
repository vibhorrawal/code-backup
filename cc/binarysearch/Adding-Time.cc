string dig(int n){
    if(n / 10) return to_string(n);
    return "0" + to_string(n);
}
string solve(string s, int n) {
    int hr;
    int min;
    bool isam = true;
    if(s[1] == ':'){
        hr = s[0] - '0';
        min = stoi(s.substr(2, 2));
        isam = s[4] == 'a';
    }
    else {
        hr = stoi(s.substr(0,2)) % 12;
        min = stoi(s.substr(3, 2));
        isam = s[5] == 'a';
    }
    int minutes = min + n;
    if(!isam) minutes += 12 * 60;
    minutes += hr * 60;
    minutes = minutes % (24 * 60);
    if(minutes == 0) return "12:00am";
    if(minutes == 12 * 60) return "12:pm";
    if(minutes >= 12 * 60) isam = false;
    else isam = true;
    string res;
    hr = minutes/60;
    if(hr > 12) hr = hr % 12;
    if(hr == 0) hr = 12;
    res += dig(hr);
    res += ":";
    min = minutes % 60;
    res += dig(min);
    if(isam) res += "am";
    else res += "pm";
    return res;
}
