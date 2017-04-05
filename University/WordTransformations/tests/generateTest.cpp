#include <map>
#include <set>
#include <queue>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>


using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> NRand(50, 100), MRand(100, 50 * 99);

void test1() { //circle
    cout << " --- start test 1 --- \n";
    ofstream out {"input1.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 1 --- \n";

    out.close();
}

void test2() { 
    cout << " --- start test 2 --- \n";
    ofstream out {"input2.in"};
    vector<string> v;

    out << "24 276\n";
    out << "ana\nbna\nbma\nama\nana\n"; //5
    out << "anc\nanna\nannc\n"; // 3
    out << "ford\nfork\nfoak\nfooak\nfooad\nforad\n"; // 6
    out << "foopk\nfopk\nfoopk\n"; // 3
    out << "zzz\nzxz\nzyz\n"; // 3
    out << "vwt\nvwv\nvvv\n"; // 3 
    out << "beric\n"; // 1

    v.push_back("ana");
    v.push_back("bna");
    v.push_back("bma");
    v.push_back("ama");
    v.push_back("ana");
    v.push_back("anc");
    v.push_back("anna");
    v.push_back("annc");
    v.push_back("ford");
    v.push_back("fork");
    v.push_back("foak");
    v.push_back("fooak");
    v.push_back("fooad");
    v.push_back("forad"); 
    v.push_back("foopk");
    v.push_back("fopk");
    v.push_back("foopk"); 
    v.push_back("zzz");
    v.push_back("zxz");
    v.push_back("zyz"); 
    v.push_back("vwt");
    v.push_back("vwv");
    v.push_back("vvv");  
    v.push_back("beric"); 

    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            out << v[i] << ' ' << v[j] << '\n';
        }
    }

    cout << " --- stop test 2 --- \n";

    out.close();
}

int min (int x, int y) {return x < y ? x : y;}

void test3() { //most should not appear
    cout << " --- start test 3 --- \n";
    ofstream out {"input3.in"};

    string s = "abcde";
    vector<string> v;

    while(next_permutation(s.begin(), s.end())) {
        v.push_back(s);

    }

    v.insert(v.begin(), {"zw", "zwc", "zwcd", "zwcde", "zbcde"});

    vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
            q.emplace_back(v[i], "fjdfdfdsf");
            q.emplace_back(v[j], "dfafdfdaf");
        }
    }

    random_shuffle(v.begin(), v.end());

    out << v.size() << " " << min(1000, q.size() + 4) << "\n";
    copy(v.begin(), v.end(), ostream_iterator<string>{out, "\n"});
    

    out << "zw zwc\nzw zwcd\nzw zwcde\nzbcde zw\n";

    random_shuffle(q.begin(), q.end());
    for (int i = 4; i < 1000; ++i) {
        out << q[i].first << ' ' << q[i].second << '\n';
    }

    cout << " --- stop test 3 --- \n";

    out.close();
}

void test4() { 
    cout << " --- start test 4 --- \n";
    ofstream out {"input4.in"};
    string s = "abcdefghij";
    vector<string> v;

    for (int i = 0; i < 10; ++i) {
        string ss = s;
        for (char c = 'k'; c <= 'w'; ++c) {
            ss[i] = c;
            v.push_back(ss);
        }
    }

    v.push_back(s);

    for (int i = 0; i < 9; ++i) {
        v.push_back(s);
        s.erase(s.end() - 1);
    }
    v.push_back(s);

    random_shuffle(v.begin(), v.end());

    out << v.size() << " 1000\n";
    copy(v.begin(), v.end(), ostream_iterator<string>{out, "\n"});
    vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    random_shuffle(q.begin(), q.end());
    for (int i = 0; i < 1000; ++i) {
        out << q[i].first << ' ' << q[i].second << '\n';
    }

    cout << " --- stop test 4 --- \n";

    out.close();
}

void test5() { //circle
    cout << " --- start test 5 --- \n";
    ofstream out {"input5.in"};
    string s = "abcdefghij";
    uniform_int_distribution<> NRand(0, 10);

    vector<string> v;

    while (s.size() > 3) {
        for (int i = 0; i < 10; ++i) {
            string ss = s;
            for (char c = 'k'; c <= 'w'; ++c) {
                ss[i] = c;
                v.push_back(ss);
            }
        }
        s.erase(s.begin() + NRand(gen) % s.size());
    }

    v.push_back(s);


    random_shuffle(v.begin(), v.end());

    out << v.size() << " 1000\n";
    copy(v.begin(), v.end(), ostream_iterator<string>{out, "\n"});
    vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    random_shuffle(q.begin(), q.end());
    for (int i = 0; i < 1000; ++i) {
        out << q[i].first << ' ' << q[i].second << '\n';
    }



    cout << " --- stop test 5 --- \n";

    out.close();
}

void test6() { 
    cout << " --- start test 6 --- \n";
    ofstream out {"input6.in"};
    uniform_int_distribution<> chRand(0, 25), NRand(1, 10);

    vector<string> v;
    do {
        int n = NRand(gen);
        string s = "";
        for (int i = 0; i < n; ++i) s.push_back(chRand(gen) + 'a');
        v.push_back(s);
    } while (v.size() != 1000);

    out << v.size() << " 1000\n";
    copy(v.begin(), v.end(), ostream_iterator<string>{out, "\n"});

    vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    for (int i = 0; i < 1000; ++i) out << q[i].first << ' ' << q[i].second << '\n';

    cout << " --- stop test 6 --- \n";

    out.close();
}

void test7() {
    cout << " --- start test 7 --- \n";
    ofstream out {"input7.in"};
    uniform_int_distribution<> chRand(0, 25), NRand(9, 10);

    vector<string> v;
    do {
        int n = NRand(gen);
        string s = "";
        for (int i = 0; i < n; ++i) s.push_back(chRand(gen) + 'a');
        v.push_back(s);
    } while (v.size() != 1000);

    out << v.size() << " 1000\n";
    copy(v.begin(), v.end(), ostream_iterator<string>{out, "\n"});

    vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    for (int i = 0; i < 1000; ++i) out << q[i].first << ' ' << q[i].second << '\n';

    cout << " --- stop test 7 --- \n";

    out.close();
}

void test8() { //circle
    cout << " --- start test 8 --- \n";
    ofstream out {"input8.in"};

    out << "17 2\n";
    out << "dip\nlip\nmad\nmap\nmaple\nmay\npad\npip\npod\npop\nsap\nsip\nslice\nslick\nspice\nstick\nstock\n";
    out << "spice stock\n";
    out << "may pod\n";

    cout << " --- stop test 8 --- \n";

    out.close();
}

void test9() { //circle
    cout << " --- start test 9 --- \n";
    ofstream out {"input9.in"};

    vector<string> v;
    vector<string> pattern1, pattern2;

    pattern1.push_back("ford");
    pattern1.push_back("fork");
    pattern1.push_back("foak");
    pattern1.push_back("fooak");
    pattern1.push_back("fooad");
    pattern1.push_back("forad"); 
    pattern1.push_back("foopk");
    pattern1.push_back("fopk");
    pattern1.push_back("foopk"); 

    pattern2.push_back("ana");
    pattern2.push_back("bna");
    pattern2.push_back("bma");
    pattern2.push_back("ama");
    pattern2.push_back("ana");
    pattern2.push_back("anc");
    pattern2.push_back("anna");
    pattern2.push_back("annc");

    v.insert(v.begin(), pattern1.begin(), pattern1.end());
    v.insert(v.begin(), pattern2.begin(), pattern2.end());

    while (v.size() <= 1000) {
        for (int j = 0; j < 4; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                for (size_t i = 0; i < pattern1.size(); ++i) {
                    string s = pattern1[i];
                    s[j] = c; 
                    v.push_back(s);
                }
            }
        }
        for (int j = 0; j < 3; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                for (size_t i = 0; i < pattern2.size(); ++i) {
                    string s = pattern2[i];
                    s[j] = c; 
                    v.push_back(s);
                }
            }
        }
    }

    random_shuffle(v.begin(), v.end());
    out << "1000 1000\n";
    for (int i = 0; i < 1000; ++i) {
        out << v[i] << '\n';
    }

  vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    random_shuffle(q.begin(), q.end());
    for (int i = 0; i < 1000; ++i) {
        out << q[i].first << ' ' << q[i].second << '\n';
    }

   

    cout << " --- stop test 9 --- \n";

    out.close();
}

void test10() { //circle
    cout << " --- start test 10 --- \n";
    ofstream out {"input10.in"};

    string s = "zyxwvutrpo";

    vector<string> v;

    while (s.size() > 1) {
        for (int i = 0; i < 10; ++i) {
            string ss = s;
            for (char c = 'k'; c <= 'w'; ++c) {
                ss[i] = c;
                v.push_back(ss);
            }
        }
        s.erase(s.begin() + NRand(gen) % s.size());
    }

    v.push_back(s);


    random_shuffle(v.begin(), v.end());
    out << "1000 1000\n";
    for (int i = 0; i < 1000; ++i) {
        out << v[i] << '\n';
    }

  vector<pair<string, string>> q;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            q.emplace_back(v[i], v[j]);
        }
    }

    random_shuffle(q.begin(), q.end());
    for (int i = 0; i < 1000; ++i) {
        out << q[i].first << ' ' << q[i].second << '\n';
    }


    cout << " --- stop test 10 --- \n";

    out.close();
}



int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
