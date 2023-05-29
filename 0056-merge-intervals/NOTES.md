a=c;
}
}
else{
vector<int>temp;
temp.push_back(a);
temp.push_back(b);
a= c;
b=d;
ans.push_back(temp);
}
}
vector<int>temp;
temp.push_back(a);
temp.push_back(b);
ans.push_back(temp);
return ans;
}
};
​
​