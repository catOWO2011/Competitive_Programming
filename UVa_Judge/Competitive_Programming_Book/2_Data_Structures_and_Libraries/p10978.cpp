
/**
13
AS ACE
2S TWO
3S THREE
4C FOUR
5C FIVE
6C SIX
7D SEVEN
8D EIGHT
9D NINE
TH TEN
JH JACK
QH QUEEN
KH KING
0
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct node {
  node<T>* prev;
  node<T>* next;
  T data;

  node (T d) {
    data = d;
  }
};

template <class T> class LinkedList {
  private:
  node<T>* first;
  node<T>* last;
  int size;

  public:
  LinkedList<T> () {
    first = NULL;
    last = NULL;
    size = 0;
  }

  void add(T data) {
    node<T>* new_node = new node<T>(data);
    if (size == 0) {
      first = last = new_node;
    } else {
      last->next = new_node;
      new_node->prev = last;
      last = new_node;
    }
    size++;
  }

  T remove(int index) {
    node<T>* current = first;

    size--;

    while (index > 0) {
      current = current->next;
      index--;
    }

    if (current->next != NULL) {
      current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
      current->prev->next = current->next;
    }

    if (current->prev == NULL) {
      first = current->next;
    }

    if (current->next == NULL) {
      last = current->prev;
    }

    return current->data;
  }

  void print() {
    node<T>* current = first;

    while (current != NULL) {
      cout<<current->data<<" ";
      current = current->next;
    }
    
    cout<<"\n";
  }

  void clear() {
    first = NULL;
    last = NULL;
    size = 0;
  }

  int length() {
    return size;
  }
};

vector<string> get_initial_card_order(vector<string> &card_values, vector<string> &card_suits, LinkedList<int> &idxs) {
  int card_amount = card_values.size();
  vector<string> order(card_amount);
  int card_suit_length = 0;
  int current_idx = 0;
  int suit_idx = 0;
  int idx_card = 0;

  while (idx_card < card_amount) {
    card_suit_length = card_suits[idx_card].length();
    current_idx = ( current_idx + card_suit_length - 1 ) % idxs.length();
    suit_idx = idxs.remove(current_idx);
    order[suit_idx] = card_values[idx_card];
    idx_card++;
  }

  return order;
}

struct card {
  string value;
  int suit_lenght;

  card (string v, int sl) {
    value = v;
    suit_lenght = sl;
  }
};

vector<string> get_initial_card_arrangement(vector<card> &cards) {
  int number_of_cards = cards.size();
  vector<string> arrangement(number_of_cards, "");
  bool is_set;
  int card_suit_length;
  int pos = 0;

  for (auto card_i: cards) {
    card_suit_length = card_i.suit_lenght;
    while (card_suit_length > 0) {
      if (arrangement[pos] == "") {
        card_suit_length--;
        if (card_suit_length == 0) {
          arrangement[pos] = card_i.value;
        }
      }
      pos = (pos + 1) % number_of_cards;
    }
  }

  return arrangement;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // ofstream myfile;
  // myfile.open("out.txt");

  int N;
  int idx;
  string value;
  string suit;
  vector<card> cards;
  vector<string> cards_order;
  
  while (cin>>N && N > 0) {
    cards.clear();
    while (N--) { 
      cin>>value>>suit;
      card c(value, suit.length());
      cards.push_back(c);
    }
    cards_order = get_initial_card_arrangement(cards);
    
    cout<<cards_order[0];
    idx = 1;
    while (idx < cards_order.size()) {
      cout<<" "<<cards_order[idx++];
    }
    cout<<"\n";
  }
  // LinkedList<int> idxs;
  // int N;
  // int idx = 0;
  // bool flag = true;
  // string card_value;
  // string card_suit;
  // vector<string> card_values;
  // vector<string> card_suits;

  // while (flag) {
  //   card_values.clear();
  //   card_suits.clear();
  //   idxs.clear();
  //   cin >> N;
  //   // cin.ignore();
  //   idx = 0;

  //   if (N == 0) {
  //     flag = false;
  //     break;
  //   }

  //   while (N--) {
  //     idxs.add(idx);
  //     cin>>card_value>>card_suit;
  //     card_values.push_back(card_value);
  //     card_suits.push_back(card_suit);
  //     // cin.ignore();
  //     idx++;
  //   }

  //   vector<string> order = get_initial_card_order(card_values, card_suits, idxs);

  //   idx = 0;
  //   cout<<order[idx];
  //   // myfile<<order[idx];
  //   idx++;
  //   while (idx < order.size()) {
  //     cout<<" "<<order[idx];
  //     // myfile<<" "<<order[idx];
  //     idx++;
  //   }
  //   // myfile<<"\n";
  //   cout<<"\n";
  // }

  // myfile.close();

  return 0;
}