#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Amirali izadpanah 

class Song {
public:
    string title;
    string artist; 
    string genre;


    Song(string t, string a, string g ) : title(t), artist(a), genre(g) {}
};

class Node {
public:
    Song song;
    Node* next;
    Node* prev;

    Node(Song s) : song(s), next(0), prev(0) {}
};

class Playlist {
private:
    Node* first;
    
public:
    Playlist() : first(0)  {} 
    
    
    int repeatly(string t ,string a )
    {
    	Node* p = first;
    	while (p) {
    		if(p->song.title == t && p->song.artist == a){
				return -1;
			}	
            p = p->next;
        }
    	return 1;
	}

    void addSong(const Song& song) {
        Node* p = new Node(song);
        if (!first) {
			first = p;
        }
		else if(repeatly(p->song.title , p->song.artist ) == -1)
		{
			cout<<"The song exist on the list"<<endl<<endl<<endl;;
		} 
		else {
			Node* q = first;
			while(q){
				if(q->next == 0){
					p->prev = q;
					p->next = 0;
					q->next = p;
					
					break;
				}
				q = q->next;
			}
        }
    }
    
    void display() const {
        Node* p = first;
        cout << "Playlist:" << endl;
        while (p) {
            cout << "Song title = " << p->song.title << " , Song artist = " << p->song.artist <<endl;
            p = p->next;
        }
        cout<<endl<<endl<<endl;
    }
    
    void remove(string s) {
    	Node* p = first;
    	int f = 0;
    	while(p) {
    		if(p->song.artist == s || p->song.title == s || p->song.genre == s) {
    			f = 1;
				if(p->prev)
					p->prev->next = p->next;
				else
					first = p->next;
				
    			if(p->next)
    				p->next->prev = p->prev;
    			else
					p->prev->next = 0;	
			}
			p = p->next;
		}
		if (f == 0)
		cout<<"Did not remove anything."<<endl<<endl;
	}
	
	void searchSong(string s) {
        Node* p = first;
        while (p) {
            if (p->song.title == s){
                cout << "Found song: " << p->song.title << " by " << p->song.artist << endl;
            }
            p = p->next;
        }
        cout<<endl<<endl<<endl;
    }
    
    void searchArtist(string s) {
        Node* p = first;
        while (p) {
            if (p->song.artist == s){
                cout << "Found artist: " << p->song.artist << " song " << p->song.title<< endl;
            }
            p = p->next;
        }
		cout<<endl<<endl<<endl;
    }
    
    
     void sortByTitle() {
        if (!first || !first->next) {
        	cout<<"Sort by artist ";
			display();
         	return;
		} 

        int s = 1;
        while (s) {
            s = 0;
            Node* p = first;
            while (p && p->next) {
                if (p->song.title > p->next->song.title) {
                    Song a = p->song;
                    p->song = p->next->song;
                    p->next->song = a;
                    s = 1;
                }
                p = p->next;
            }
        } 
        cout<<"Sort by title ";
        display();
    }

    void sortByArtist() {
        if (!first || !first->next) {
			cout<<"Sort by artist ";
			display();
         	return;
		} 

        int s =1;
        while (s){
            s = 0;
            Node* p = first;

            while (p && p->next) {
                if (p->song.artist > p->next->song.artist) {
                    Song a = p->song;
                    p->song = p->next->song;
                    p->next->song = a;
                    s = 1;
                }
                p = p->next;
            }
        } 
        cout<<"Sort by artist ";
        display();
    }
    
    
    
    void playRandom() const {
		Node* q = first;
    	int size=0;
    	while (q){
    		q = q->next;
    		size++;
		}
		
		srand((time(0)));
    	int j = rand()  % size + 1;
    	
    	Node* p = first;
        for(int i = 0; i<j-1; i++){
        	p = p->next;
		}
		cout<<"Random :"<<endl;
		while (p) {
            cout << "Song title = " << p->song.title << " , Song artist = " << p->song.artist <<endl;
            p = p->prev;
        }
              
        p = first;
        for(int i = 0; i<j; i++){
        	p = p->next;
		}

 		while (p) {
            cout << "Song title = " << p->song.title << " , Song artist = " << p->song.artist <<endl;
            p = p->next;
        }
        
        cout<<endl<<endl<<endl;
        
    }
	
	void moveUp(int pos1 ) {
		if(pos1 <=0)
			return;
			
        Node* p = first;
        
		for(int i = 0; i < pos1-1; i++){
			p = p->next;
		}
		
		if (p && p->prev) {
			Node* temp = new Node(p->song);
			p->song = p->prev->song;
			p->prev->song = temp->song;
  		}
  		
  		display();
	}
	
	void moveDown(int pos1 ) {
		if(pos1 <=0)
			return;
			
        Node* p = first;
        
		for(int i = 0; i < pos1-1; i++){
			p = p->next;
		}
		
		if (p && p->prev) {
			Node* temp = new Node(p->song);
			p->song = p->next->song;
			p->next->song = temp->song;
  		}
  		
  		display();
	}

	    
};

int main() {
    Playlist playlist;
    
    /*playlist.addSong(Song("Pedar Man", "Zed Bazi", "Rap"));
    playlist.addSong(Song("Pedar Man", "Zed Bazi", "Rap"));
    
    playlist.addSong(Song("Ghese Eshgh", "Ebi", "Pop"));
    playlist.addSong(Song("Asar manfi", "Reza Pishro", "Rap")); 
    playlist.addSong(Song("Ghors 2", "Hiphopologist", "Melodic"));	
	playlist.addSong(Song("Doctor", "Sasy", "Party"));
	playlist.addSong(Song("Ghors 1", "Hiphopologist", "Melodic"));
	playlist.addSong(Song("Dore Donya", "Reza Pishro", "Classic"));
	playlist.display();
	
	
    
	cout<<"Move down 3: "<<endl;
	playlist.moveDown(3);
	
	cout<<"Move up 6: "<<endl;
	playlist.moveUp(6);
	
    
    playlist.searchSong("Pedar Man");
    playlist.searchArtist("Reza Pishro");
    playlist.searchArtist("Hiphopologist");
    
    playlist.playRandom();
     
    playlist.sortByArtist();
    playlist.sortByTitle();
    
    cout<<"Remove Ebi"<<endl;
    playlist.remove("Ebi");  playlist.display();*/
    
    
    /*int n =-1;
    cout<<"Add song = 1"<<endl;
    cout<<"Remove song = 2"<<endl;
    cout<<"Search song = 3"<<endl;
    cout<<"Search artist = 4"<<endl;
    cout<<"Sort song by titele = 5"<<endl;
    cout<<"Sort song by artist = 6"<<endl;
    cout<<"Move down song = 7"<<endl;
    cout<<"Move up song = 8"<<endl;
    cout<<"Play random song = 9"<<endl;
    cout<<"display list = 10"<<endl;
    cout<<"End = 0"<<endl<<endl;

    while(n !=0)
    {
    	cout<<"Please Enter code : ";
    	cin>>n;
    	
    	if(n ==1){
    		string a,b,c="   ";
    		cout<<"Enter song name : ";
    		cin>>a;
    		cout<<"Enter artist name : ";
    		cin>>b;
    		cout<<"Enter genre name : ";
    		cin>>c;
    		
    		playlist.addSong(Song(a, b, c));
		}
		
		else if(n ==2){
			string a = "   ";
			cout<<"Enter song name or artist name : ";
    		cin>>a;
    		playlist.remove(a);
		}
		
		else if(n ==3){
			string a = "   ";
			cout<<"Enter song name : ";
    		cin>>a;
    		playlist.searchSong(a);
		}
		
		else if(n ==4){
			string a = "   ";
			cout<<"Enter artist name : ";
    		cin>>a;
    		playlist.searchArtist(a);
		}
		
		else if(n ==5){
			playlist.sortByTitle();
		}
		
		else if(n ==6){
			playlist.sortByArtist();
		}
		
		else if(n ==7){
			int z ;
			cout<<"Enter num track : ";
    		cin>>z;
    		playlist.moveDown(z);
		}
		
		else if(n ==8){
			int z ;
			cout<<"Enter num track : ";
    		cin>>z;
			playlist.moveUp(z);
		}
		
		else if(n ==9){
			playlist.playRandom();
		}
		
		else if(n ==10){
			playlist.display();
		}
		
		else if (n ==0){
			cout<<"End project :)";
			break;
		}
		
		else{
			cout<<"Wrong code !!!"<<endl;
		}
    	
    }*/
   
    return 0;
}

