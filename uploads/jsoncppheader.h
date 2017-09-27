#ifndef JSONCPPHEADER_H_INCLUDED
#define JSONCPPHEADER_H_INCLUDED
#include <string>
#include "json/json.h"
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;
int TracerCount = 0;
class Mylist{
public:
    Json::Value mlist;
    Mylist() {
    }
    void append(Json::Value v) {
        mlist.append(v);
    }
    ~Mylist() {
        Json::FastWriter fw;
        std::string res_str = fw.write(mlist);
        std::cout << res_str << std::endl;
    }
};
Mylist mylist;
class Array2DTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    Array2DTracer(string name = ""){
        id = TracerCount++;
        type = "Array2DTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    Array2DTracer& palette(string selected, string notified, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(selected));
        tmp.append(Json::Value(notified));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& setData(int *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i].append(D[i * len + j]);
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& setData(char *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string s = "";
                s += D[i * len + j];
                tmp[i].append(s);
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& notify(int x, int y, int v) {
		JSONObeject["Event"] = Json::Value("notify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
        tmp["v"] = Json::Value(v);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& denotify(int x, int y) {
		JSONObeject["Event"] = Json::Value("denotify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& select(int sx, int sy, int ex, int ey) {
		JSONObeject["Event"] = Json::Value("selectRT");
		Json::Value tmp;
		tmp["sx"] = Json::Value(sx);
        tmp["sy"] = Json::Value(sy);
        tmp["ex"] = Json::Value(ex);
        tmp["ey"] = Json::Value(ey);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& select(int x, int y) {
		JSONObeject["Event"] = Json::Value("select");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& selectRow(int x, int sy, int ey) {
		JSONObeject["Event"] = Json::Value("selectRow");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["sy"] = Json::Value(sy);
        tmp["ey"] = Json::Value(ey);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& selectCol(int y, int sx, int ex) {
		JSONObeject["Event"] = Json::Value("selectCol");
		Json::Value tmp;
		tmp["y"] = Json::Value(y);
        tmp["sx"] = Json::Value(sx);
        tmp["ex"] = Json::Value(ex);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deselect(int sx, int sy, int ex, int ey) {
		JSONObeject["Event"] = Json::Value("deselectRT");
		Json::Value tmp;
		tmp["sx"] = Json::Value(sx);
        tmp["sy"] = Json::Value(sy);
        tmp["ex"] = Json::Value(ex);
        tmp["ey"] = Json::Value(ey);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deselect(int x, int y) {
		JSONObeject["Event"] = Json::Value("deselect");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deselectRow(int x, int sy, int ey) {
		JSONObeject["Event"] = Json::Value("deselectRow");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["sy"] = Json::Value(sy);
        tmp["ey"] = Json::Value(ey);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deselectCol(int y, int sx, int ex) {
		JSONObeject["Event"] = Json::Value("deselectCol");
		Json::Value tmp;
		tmp["y"] = Json::Value(y);
        tmp["sx"] = Json::Value(sx);
        tmp["ex"] = Json::Value(ex);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& separate(int x, int y) {
		JSONObeject["Event"] = Json::Value("separate");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& separateRow(int x) {
		JSONObeject["Event"] = Json::Value("separateRow");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& separateCol(int y) {
		JSONObeject["Event"] = Json::Value("separateCol");
		Json::Value tmp;
		tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deseparate(int x, int y) {
		JSONObeject["Event"] = Json::Value("deseparate");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deseparateRow(int x) {
		JSONObeject["Event"] = Json::Value("deseparateRow");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& deseparateCol(int y) {
		JSONObeject["Event"] = Json::Value("deseparateCol");
		Json::Value tmp;
		tmp["y"] = Json::Value(y);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array2DTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    Array2DTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    Array2DTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


};

class Array1DTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    Array1DTracer(string name = ""){
        id = TracerCount++;
        type = "Array1DTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    Array1DTracer& palette(string selected, string notified, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(selected));
        tmp.append(Json::Value(notified));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& setData(int *D, int n) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            tmp.append(D[i]);
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& setData(char *D, int n) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            string s = "";
            s += D[i];
            tmp.append(s);
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& notify(int x, int v) {
		JSONObeject["Event"] = Json::Value("notify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["v"] = Json::Value(v);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& denotify(int x) {
		JSONObeject["Event"] = Json::Value("denotify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


	Array1DTracer& select(int s, int e) {
		JSONObeject["Event"] = Json::Value("selectR");
		Json::Value tmp;
		tmp["s"] = Json::Value(s);
		tmp["e"] = Json::Value(e);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& select(int x) {
		JSONObeject["Event"] = Json::Value("select");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& deselect(int s, int e) {
		JSONObeject["Event"] = Json::Value("deselectR");
		Json::Value tmp;
		tmp["s"] = Json::Value(s);
		tmp["e"] = Json::Value(e);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& deselect(int x) {
		JSONObeject["Event"] = Json::Value("deselect");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


	Array1DTracer& separate(int x) {
		JSONObeject["Event"] = Json::Value("separate");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& deseparate(int x) {
		JSONObeject["Event"] = Json::Value("deseparate");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	Array1DTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    Array1DTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    Array1DTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
};

class LogTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    LogTracer(string name = ""){
        id = TracerCount++;
        type = "LogTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }

    LogTracer& print(string info) {
		JSONObeject["Event"] = Json::Value("print");
		Json::Value tmp;
		tmp["info"] = Json::Value(info);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	LogTracer& print(char *info, int n) {
		JSONObeject["Event"] = Json::Value("print");
		Json::Value tmp;
		string s = "";
		for(int i = 0; i < n; i++) s += info[i];
		tmp["info"] = Json::Value(s);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	LogTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    LogTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

};

class ChartTracer{
public:
    int id;
    string type;
    Json::Value JSONObeject;
    ChartTracer(string name = ""){
        id = TracerCount++;
        type = "ChartTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    ChartTracer& palette(string selected, string notified, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(selected));
        tmp.append(Json::Value(notified));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& setData(int *D, int n) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            tmp.append(D[i]);
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& setData(char *D, int n) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            string s = "";
            s += D[i];
            tmp.append(s);
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& notify(int x, int v) {
		JSONObeject["Event"] = Json::Value("notify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        tmp["v"] = Json::Value(v);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& denotify(int x) {
		JSONObeject["Event"] = Json::Value("denotify");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


	ChartTracer& select(int s, int e) {
		JSONObeject["Event"] = Json::Value("selectR");
		Json::Value tmp;
		tmp["s"] = Json::Value(s);
		tmp["e"] = Json::Value(e);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& select(int x) {
		JSONObeject["Event"] = Json::Value("select");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& deselect(int s, int e) {
		JSONObeject["Event"] = Json::Value("deselectR");
		Json::Value tmp;
		tmp["s"] = Json::Value(s);
		tmp["e"] = Json::Value(e);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& deselect(int x) {
		JSONObeject["Event"] = Json::Value("deselect");
		Json::Value tmp;
		tmp["x"] = Json::Value(x);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	ChartTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    ChartTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
};

class DirectedGraphTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    DirectedGraphTracer(string name = ""){
        id = TracerCount++;
        type = "DirectedGraphTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    DirectedGraphTracer& palette(string visit, string left, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(visit));
        tmp.append(Json::Value(left));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	DirectedGraphTracer& setData(int *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * len + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	DirectedGraphTracer& setTreeData(int *D, int n, int m, int root) {
		JSONObeject["Event"] = Json::Value("setTreeData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp["Data"][i][j] = D[i * n + j];
            }
		}
    tmp["root"] = root;
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


	DirectedGraphTracer& visit(int t, int s) {
		JSONObeject["Event"] = Json::Value("visit");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
  
  DirectedGraphTracer& visit(int t) {
		JSONObeject["Event"] = Json::Value("visit");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	DirectedGraphTracer& leave(int t, int s) {
		JSONObeject["Event"] = Json::Value("leave");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	DirectedGraphTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    DirectedGraphTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	DirectedGraphTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

};

class UndirectedGraphTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    UndirectedGraphTracer(string name = ""){
        id = TracerCount++;
        type = "UndirectedGraphTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    UndirectedGraphTracer& palette(string visit, string left, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(visit));
        tmp.append(Json::Value(left));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	UndirectedGraphTracer& setData(int *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * len + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	UndirectedGraphTracer& setTreeData(int *D, int n, int m) {
		JSONObeject["Event"] = Json::Value("setTreeData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * n + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}


	UndirectedGraphTracer& visit(int t, int s) {
		JSONObeject["Event"] = Json::Value("visit");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	UndirectedGraphTracer& leave(int t, int s) {
		JSONObeject["Event"] = Json::Value("leave");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	UndirectedGraphTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    UndirectedGraphTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	UndirectedGraphTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
};

class WeightedDirectedGraphTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    WeightedDirectedGraphTracer(string name = ""){
        id = TracerCount++;
        type = "WeightedDirectedGraphTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    WeightedDirectedGraphTracer& palette(string visit, string left, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(visit));
        tmp.append(Json::Value(left));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& setData(int *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * len + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& setTreeData(int *D, int n, int m) {
		JSONObeject["Event"] = Json::Value("setTreeData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * n + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    WeightedDirectedGraphTracer& weight(int t, int w) {
		JSONObeject["Event"] = Json::Value("weight");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& visit(int t, int s, int w) {
		JSONObeject["Event"] = Json::Value("visit");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& leave(int t, int s, int w) {
		JSONObeject["Event"] = Json::Value("leave");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    WeightedDirectedGraphTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedDirectedGraphTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
};

class WeightedUndirectedGraphTracer {
public:
    int id;
    string type;
    Json::Value JSONObeject;
    WeightedUndirectedGraphTracer(string name = ""){
        id = TracerCount++;
        type = "WeightedUndirectedGraphTracer";
        JSONObeject["ID"] = Json::Value(id);
        JSONObeject["Type"] = Json::Value(type);
        JSONObeject["Event"] = Json::Value("init");
        JSONObeject["Data"] = Json::Value(name);
        mylist.append(Json::Value(JSONObeject));
    }
    WeightedUndirectedGraphTracer& palette(string visit, string left, string _default) {
        JSONObeject["Event"] = Json::Value("palette");
        Json::Value tmp;
        tmp.append(Json::Value(visit));
        tmp.append(Json::Value(left));
        tmp.append(Json::Value(_default));
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& setData(int *D, int len, int n, int m) {
		JSONObeject["Event"] = Json::Value("setData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * len + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& setTreeData(int *D, int n, int m) {
		JSONObeject["Event"] = Json::Value("setTreeData");
		Json::Value tmp;
		for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                tmp[i][j] = D[i * n + j];
            }
		}
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    WeightedUndirectedGraphTracer& weight(int t, int w) {
		JSONObeject["Event"] = Json::Value("weight");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& visit(int t, int s, int w) {
		JSONObeject["Event"] = Json::Value("visit");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& leave(int t, int s, int w) {
		JSONObeject["Event"] = Json::Value("leave");
		Json::Value tmp;
		tmp["t"] = Json::Value(t);
        tmp["s"] = Json::Value(s);
        tmp["w"] = Json::Value(w);
		JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& wait(int line) {
		JSONObeject["Event"] = Json::Value("wait");
		Json::Value tmp;
		tmp["line"] = Json::Value(line);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

    WeightedUndirectedGraphTracer& clear() {
		JSONObeject["Event"] = Json::Value("clear");
		Json::Value tmp;
		tmp.resize(0);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}

	WeightedUndirectedGraphTracer& attach(int id) {
		JSONObeject["Event"] = Json::Value("attach");
		Json::Value tmp;
		tmp["id"] = Json::Value(id);
        JSONObeject["Data"] = tmp;
		mylist.append(Json::Value(JSONObeject));
		return *this;
	}
};


#endif // JSONCPPHEADER_H_INCLUDED
