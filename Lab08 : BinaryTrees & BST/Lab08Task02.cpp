#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string name;
    int playCount;
    Song* lessPopular;
    Song* morePopular;

    Song(string n, int p) {
        name = n;
        playCount = p;
        lessPopular = morePopular = nullptr;
    }
};

Song* addSong(Song* root, string name, int playCount) {
    if (!root) return new Song(name, playCount);
    if (playCount < root->playCount)
        root->lessPopular = addSong(root->lessPopular, name, playCount);
    else if (playCount > root->playCount)
        root->morePopular = addSong(root->morePopular, name, playCount);
    else
        cout << "Song with play count " << playCount << " already exists.\n";
    return root;
}

Song* findSong(Song* root, int playCount) {
    if (!root || root->playCount == playCount) return root;
    if (playCount < root->playCount) return findSong(root->lessPopular, playCount);
    else return findSong(root->morePopular, playCount);
}

void showSongsByPopularity(Song* root) {
    if (!root) return;
    showSongsByPopularity(root->lessPopular);
    cout << root->name << " (" << root->playCount << " plays)" << endl;
    showSongsByPopularity(root->morePopular);
}

void removeSongsReversePopularity(Song* root) {
    if (!root) return;
    removeSongsReversePopularity(root->lessPopular);
    removeSongsReversePopularity(root->morePopular);
    cout << root->name << " (" << root->playCount << " plays)" << endl;
}

Song* minPlayCountSong(Song* node) {
    Song* current = node;
    while (current && current->lessPopular)
        current = current->lessPopular;
    return current;
}

Song* removeSong(Song* root, int playCount) {
    if (!root) return root;
    if (playCount < root->playCount)
        root->lessPopular = removeSong(root->lessPopular, playCount);
    else if (playCount > root->playCount)
        root->morePopular = removeSong(root->morePopular, playCount);
    else {
        if (!root->lessPopular) {
            Song* temp = root->morePopular;
            delete root;
            return temp;
        } else if (!root->morePopular) {
            Song* temp = root->lessPopular;
            delete root;
            return temp;
        }
        Song* temp = minPlayCountSong(root->morePopular);
        root->playCount = temp->playCount;
        root->name = temp->name;
        root->morePopular = removeSong(root->morePopular, temp->playCount);
    }
    return root;
}

int main() {
    Song* root = nullptr;
    root = addSong(root, "Song A", 10);
    root = addSong(root, "Song B", 50);
    root = addSong(root, "Song C", 30);
    root = addSong(root, "Song D", 20);
    root = addSong(root, "Song E", 40);

    cout << "Songs from least to most played:\n";
    showSongsByPopularity(root);
    cout << "Songs removed in reverse popularity:\n";
    removeSongsReversePopularity(root);

    int searchCount = 30;
    Song* found = findSong(root, searchCount);
    if (found)
        cout << "Song found: " << found->name << " (" << found->playCount << " plays)\n";
    else
        cout << "No song with play count " << searchCount << " found.\n";

    searchCount = 25;
    found = findSong(root, searchCount);
    if (found)
        cout << "Song found: " << found->name << " (" << found->playCount << " plays)\n";
    else
        cout << "No song with play count " << searchCount << " found.\n";

    int deleteCount = 30;
    root = removeSong(root, deleteCount);
    cout << "After removing play count " << deleteCount << ", songs from least to most played:\n";
    showSongsByPopularity(root);

    return 0;
}
