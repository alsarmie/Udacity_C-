#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct Node {
  Node() {}
  Node(Node *p, string t) : parent(p), tag(t) {}
  Node *parent = nullptr;
  string tag;
};
void ParseData(unordered_map<string, vector<pair<string, string>>> &dict,
               vector<Node *> &hierarchy, Node *&current, int &n) {
  string line;
  getline(cin, line);
  string tag, attribute, value;
  // Decide if we are dealing with opening tags or closing tags.
  if (line[1] != '/') {
    tag = line.substr(1, line.find(' ') - 1);
    line.erase(0, line.find(' '));
    line.erase(line.find('>'), line.find('>'));
    // Add tag to hierarchy

    // new_tag.tag = tag;
    // if (n != 0)
    // new_tag.parent = current;
    // current = &new_tag;
    hierarchy.emplace_back(new Node(current, tag));
    current = hierarchy.back();
    // cout<<"alive\n";
    // Extract the attributes.
    while (line.size()) {
      // Find Attribute
      attribute = line.substr(line.find(' ') + 1, line.find('=') - 2);
      line.erase(0, line.find('=') + 3);
      // Get Value Attribute
      value = line.substr(0, line.find('"'));
      line.erase(0, line.find('"') + 1);
      // Add value to the map
      dict[tag].push_back({attribute, value});
    }
  } else { // check that the tag exists when closing and check hierarchy
    tag = line.substr(2, line.find('>') - 2);
    line.clear();
    // Find node that matches the closing tag
    for (const auto &node : hierarchy)
      if (node->tag == tag)
        current = node->parent;

    assert((dict.find(tag) != dict.end()));
  }

  // for(auto node:hierarchy)
  //  cout<<" Tag: "<<node->tag<<endl;
}
void ParseQuery(unordered_map<string, vector<pair<string, string>>> &dict,
                vector<Node *> &hierarchy) {
  string line;
  getline(cin, line);
  string tag, attribute, value;
  vector<string> tags;
  int idx;
  bool found = false;
  // Determine if we have several tags
  idx = line.find("~");
  attribute = line.substr(idx + 1, line.back());
  line.erase(idx, line.back());
  tag = line;
  idx = line.find('.');

  if (idx > 0) { // We have several tags
    // check that tags exist and are in correct hierarchy
    while (line.size()) {
      tag = line.substr(0, idx);
      line.erase(0, idx + 1);
      tags.emplace_back(tag);
    }

    for (int i = 0; i < tags.size() - 1; i++) {
      for (const auto &node : hierarchy)
        if (node->tag == tag && node->parent == nullptr)
        
    }
  }
}
else { // we have only one tag
  found = false;
  for (const auto &node : hierarchy)
    if (node->tag == tag &&
        node->parent == nullptr) { // Check that the tag is the root
      if (dict.find(tag) != dict.end()) {
        for (const auto &attribute_value : dict[tag])
          if (attribute_value.first == attribute) {
            cout << attribute_value.second << endl;
            found = true;
          }
        if (!found)
          cout << "Not Found!" << endl;
      } else
        cout << "Not Found!" << endl;
    } else {
      cout << "Not Found!" << endl;
    }
}
}
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N{0}, Q{0};
  Node *current = nullptr;
  vector<Node *> tag_hierarchy;
  unordered_map<string, vector<pair<string, string>>> tag_dict;

  // read N and Q;
  cin >> N >> Q;
  cin.ignore(256, '\n');
  // parse the HRML lines
  for (int n = 0; n < N; n++) {
    ParseData(tag_dict, tag_hierarchy, current, n);
    /*     cout << " Tag in node: " << node.tag << endl;
        cout << "----------------------------" << endl;
        cout << "Size of tree " << tag_hierarchy.size() << endl;
        for (const auto &nd : tag_hierarchy) {
          cout << "Tag in hierarchy: " << nd->tag << " Parent: " << nd->parent
               << endl;
        }

        cout << "----------------------------" << endl; */
  }

  // for(auto nodes:tag_hierarchy)
  //  cout<<" Tag: "<<nodes->tag<<endl;

  // parse the queries
  for (int q = 0; q < Q; q++)
    ParseQuery(tag_dict, tag_hierarchy);

  return 0;
}
