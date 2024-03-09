import java.util.ArrayList;
import java.util.List;

public class Dataset { // to define dataset class.

    private List<DatasetObject> dataset; // to define a list for store the dataset objects.
    private List<Observer> observers; // to define a list for store the observers.
    private List<Player> players; // to define a list for store the players.
    private List<Viewer> viewers;// to define a list for store the viewers.

    public Dataset() { // to define default constructor.
        dataset = new ArrayList<DatasetObject>();
        observers = new ArrayList<Observer>();
        players = new ArrayList<Player>();
        viewers = new ArrayList<Viewer>();
    }

    public void add(DatasetObject obj) { // to define add function.
        /*
         * This function gets a datasetobject and it adds that object to relevant list
         * and it updates the observers.
         */
        dataset.add(obj); // to add the given object to the datasetobject list.
        notifyObservers(obj, "add"); // to notify observers and add that object to observers.
        if (obj instanceof Playable) { // to check object type is Playable or not.
            for (Player p : players) {
                p.update(obj, "add"); // to add that object to playlist with using update function of observer.
            }
        }
        if (obj instanceof NonPlayable) { // to check object type is NonPlayable or not.
            for (Viewer v : viewers) {
                v.update(obj, "add");// to add that object to viewlist with using update function of observer.
            }
        }
    }

    public void remove(DatasetObject obj) { // to define remove function.
        /*
         * This function gets a datasetobject and it removes that object to relevant
         * list and it updates the observers.
         */
        dataset.remove(obj);// to remove the given object to the datasetobject list.
        notifyObservers(obj, "remove");// to notify observers and remove that object to observers.
        if (obj instanceof Playable) { // to check object type is Playable or not.
            for (Player p : players) {
                p.removeFromPlayerList(obj);
                p.update(obj, "remove");// to remove that object to playlist with using update function of observer.
            }
        }
        if (obj instanceof NonPlayable) {
            for (Viewer v : viewers) {
                v.removeFromViewList(obj);
                v.update(obj, "remove");// to remove that object to viewlist with using update function of observer.
            }
        }

    }

    public void register(Observer observer) { // to define register function.
        observers.add(observer); // to add the given observer to observers list in dataset object.
    }

    public void removeObserver(Observer observer) { // to define removeObserver function.
        observers.remove(observer);// to remove the given observer to observers list in dataset object.
    }

    public void notifyObservers(DatasetObject obj, String forWhat) { // to define notifyObservers function.
        for (Observer observer : observers) {
            observer.update(obj, forWhat); // to update all the observers.
        }
    }
}
