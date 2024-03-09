
public class main {

    public static void main(String[] args) {
        // This is our dataset. We have only one dataset.
        Dataset ds = new Dataset();
        // Lets create different observers.
        Player p1 = new Player();
        Player p2 = new Player();
        Viewer v1 = new Viewer();
        Viewer v2 = new Viewer();
        // Lets register them to our dataset so that they can reach to data and updates.
        // You can also register them to the dataset when you create them.
        // ds has to figure out the type of the observer.
        // it should not send unrelated information.
        // For example, viewer objects don't want to know anything about playable
        // objects.
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        // Dataset should also support un-registering.
        // ds.remove_observer(p1);
        // p1 no longer receives any update or list of items.
        // Here we create different objects.
        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));
        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));
        ds.add(new Video("videoname1", "duration1", "other info1"));
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));
        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));
        // Lets use one of the player objects.
        // We can get the currently playing object
        Playable po = p1.currentlyPlaying();
        // This prints info about the playing object.
        po.info();
        // we can remove this object from the dataset
        ds.remove((DatasetObject) po);
        // po is no longer in the dataset. all of the interested observers will get this
        // update.
        // similarly, viewer object:
        ds.add(new Text("textname4", "other info4"));
        NonPlayable np = v1.currentlyViewing();
        np.info(); // this prints info about the object being viewed.
        p1.showList();
        v1.showList();

    }
}