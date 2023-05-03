int n;
    cin>>n;
    int i=1;
    while(i<=n){

        int j=1;
        // int value=1;
        while(j<=n-i+1){
            cout<<j;
            // value=value+1;
            j=j+1;
        }

        int space=1;
        while(space<=i-1){
            cout<<"*";
            space=space+1;
        }

        int space2=1;
        while(space2<=i-1){
            cout<<"*";
            space2=space2+1;
        }

        int j1=n-i+1;
        while(j1>=1){
            cout<<j1;
            j1=j1-1;
        }

        cout<<endl;
        i=i+1;
    }