import java.util.ArrayList;
import java.util.List;

public class Player implements Observer { // to define Player class.
    private List<Playable> playList; // to define a list for playlists.
    private int currentPlaying; // to define an integer for current playing index.

    public Player() {// to define default constructor.
        playList = new ArrayList<Playable>();
        currentPlaying = 0;
    }

    public List<Playable> getPlayList() { // to define getter function for playlist.
        return playList;
    }

    public Playable currentlyPlaying() { // to define currentlyPlaying function.
        return playList.get(currentPlaying); // it returns curently playing playable object.
    }

    @Override
    public void update(DatasetObject datasetObject, String forWhat) {// to define update function.
        if (datasetObject instanceof Playable) {
            if (forWhat == "add") { // this block for updating for adding an object.
                Playable playable = (Playable) datasetObject;
                playList.add(playable);
            } else if (forWhat == "remove") {// this block for updating for removing an object.
                playList.remove(datasetObject);
            }
        }
    }

    public void next(String type) { // to define next function.
        /*
         * This function gets a string for type of dataset object and it changes
         * currently playing object to next object of given type.
         */
        if (playList == null || playList.isEmpty()) { // to check playlist is empty or not.
            System.out.println("Playlist is empty.");
        } else {
            if (type.equals("Audio")) { // this if block for Audio objects.
                currentPlaying = (currentPlaying + 1) % playList.size();
                while (!(playList.get(currentPlaying) instanceof Audio)) {
                    currentPlaying = (currentPlaying + 1) % playList.size(); // to get mod because if it is last element  then goes first element.
                }
            } else if (type.equals("Video")) { // this if block for Video objects.
                currentPlaying = (currentPlaying + 1) % playList.size();
                while (!(playList.get(currentPlaying) instanceof Video)) {
                    currentPlaying = (currentPlaying + 1) % playList.size(); // to get mod because if it is last element then goes first element.
                }
            }
        }
    }

    public void previous(String type) { // to define previous function.
        /*
         * This function gets a string for type of dataset object and it changes
         * currently playing object to previous object of given type.
         */
        if (playList == null || playList.isEmpty()) { // to check playlist is empty or not.
            System.out.println("Playlist is empty.");
        } else {
            if (type.equals("Audio")) {// this if block for Audio objects.
                currentPlaying = (currentPlaying - 1 + playList.size()) % playList.size();
                while (!(playList.get(currentPlaying) instanceof Audio)) {
                    currentPlaying = (currentPlaying - 1 + playList.size()) % playList.size();// to get mod because if it is first element then goes last element.
                }
            } else if (type.equals("Video")) { // this if block for Video object.
                currentPlaying = (currentPlaying - 1 + playList.size()) % playList.size();
                while (!(playList.get(currentPlaying) instanceof Video)) {
                    currentPlaying = (currentPlaying - 1 + playList.size()) % playList.size();// to get mod because if it is first element then goes last element.
                }
            }
        }
    }

    public void showList() { // to define showlist function.
        /*
         * This function shows objects of the playlist.
         */
        if (playList.isEmpty()) { // to check playlist is empty or not.
            System.out.println("No items in playlist");
            return;
        }
        System.out.println("Playlist:");
        for (Playable p : playList) {
            System.out.println(p.getName());
        }
    }

    public void removeFromPlayerList(DatasetObject datasetObject) { // to define remove from play list.
        /*
         * This function takes a dataset object and it removes that object from the
         * playlist.
         */
        if (playList == null || playList.isEmpty()) {
            System.out.println("Play list is empty.");
        } else if (playList.contains(datasetObject)) { // to check given object is in playlist or not.
            playList.remove(datasetObject); // to remove that object from list.
            if (currentPlaying >= playList.size()) {
                currentPlaying = 0; // to reset current position if removed last object
            }
            System.out.println(datasetObject.getName() + " removed from play list.");
        } else {
            System.out.println(datasetObject.getName() + " is not in the play list.");
        }
    }
}