import java.util.ArrayList;
import java.util.List;

public class Viewer implements Observer { //to define viewer class.
    private List<NonPlayable> viewList; //to define a list for viewlist.
    private int currentViewing; //to define an integer for current viewing object's index.

    public Viewer() {// to define default constructor.
        viewList = new ArrayList<>();
    }

    public List<NonPlayable> getViewList() {// to define getter function for viewlist.
        return viewList;
    }

    public NonPlayable currentlyViewing() { //to define currentlyViewing function.
        if (viewList.isEmpty()) {
            return null;
        }
        return viewList.get(currentViewing); //to return currently viewing object.
    }

    @Override
    public void update(DatasetObject datasetObject, String forWhat) {// to define update function.
        if (datasetObject instanceof NonPlayable) {
            if (forWhat == "add") {// this block for updating for adding an object.
                NonPlayable nonplayable = (NonPlayable) datasetObject;
                viewList.add(nonplayable);
            } else if (forWhat == "remove") {// this block for updating for removing an object.
                viewList.remove(datasetObject);
            }
        }
    }

    public void next(String type) {// to define next function.
                /*
         * This function gets a string for type of dataset object and it changes
         * currently viewing object to next object of given type.
         */
        if (viewList == null || viewList.isEmpty()) {// to check viewlist is empty or not.
            System.out.println("View list is empty.");
        } else {
            if (type.equals("Text")) { //this if block for Text object.
                currentViewing = (currentViewing + 1) % viewList.size();
                while (!(viewList.get(currentViewing) instanceof Text)) {
                    currentViewing = (currentViewing + 1) % viewList.size(); // to get mod because if it is last element then goes first element.
                }
            } else if (type.equals("Image")) { //this if block for Image object.
                currentViewing = (currentViewing + 1) % viewList.size();
                while (!(viewList.get(currentViewing) instanceof Image)) {
                    currentViewing = (currentViewing + 1) % viewList.size(); // to get mod because if it is last element then goes first element.
                }
            }
        }
    }

    public void previous(String type) { //to define previous function.
                        /*
         * This function gets a string for type of dataset object and it changes
         * currently viewing object to previous object of given type.
         */
        if (viewList == null || viewList.isEmpty()) {// to check viewlist is empty or not.
            System.out.println("View list is empty.");
        } else {
            if (type.equals("Text")) {//this if block for Text object.
                currentViewing = (currentViewing - 1 + viewList.size()) % viewList.size();
                while (!(viewList.get(currentViewing) instanceof Text)) {
                    currentViewing = (currentViewing - 1 + viewList.size()) % viewList.size();// to get mod because if it is first element then goes last element.
                }
            } else if (type.equals("Image")) {
                currentViewing = (currentViewing - 1 + viewList.size()) % viewList.size();
                while (!(viewList.get(currentViewing) instanceof Image)) {
                    currentViewing = (currentViewing - 1 + viewList.size()) % viewList.size();// to get mod because if it is first element then goes last element.
                }
            }
        }
    }

    public void showList() {// to define showlist function.
        /*
         * This function shows objects of the viewlist.
         */
        if (viewList.isEmpty()) { // to check viewlist is empty or not.
            System.out.println("No items in viewlist");
            return;
        }
        System.out.println("Viewlist:");
        for (NonPlayable nv : viewList) {
            System.out.println(nv.getName());
        }
    }

    public void removeFromViewList(DatasetObject datasetObject) { //to define remove from viewlist function.
        /*
         * This function takes a dataset object and it removes that object from the
         * viewlist.
         */
        if (viewList == null || viewList.isEmpty()) {// to check viewlist is empty or not.
            System.out.println("View list is empty.");
        } else if (viewList.contains(datasetObject)) { // to check given object is in viewlist or not
            viewList.remove(datasetObject); // to remove that object from list.
            if (currentViewing >= viewList.size()) {
                currentViewing = 0; //to reset current position if removed last object
            }
            System.out.println(datasetObject.getName() + " removed from view list.");
        } else {
            System.out.println(datasetObject.getName() + " is not in the view list.");
        }
    }
}
