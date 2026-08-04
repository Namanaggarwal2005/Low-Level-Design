#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include "./Restaurant.cpp"

using namespace std;

class RestaurantManager {
private:
    vector<Restaurant> restaurants;
    static RestaurantManager* instance;
    static mutex mut;

    // Private constructor
    RestaurantManager() {}


public:
    // Singleton instance
    static RestaurantManager* getInstance() {
        if(instance==nullptr){
            mut.lock();
            if(instance==nullptr)
                instance = new RestaurantManager();
            mut.unlock();
        }
        return instance;
    }

    // CREATE
    void addRestaurant(const Restaurant& restaurant) {
        restaurants.push_back(restaurant);
    }

    // READ
    Restaurant* getRestaurantById(int id) {
        for (auto& restaurant : restaurants) {
            if (restaurant.getId() == id) {
                return &restaurant;
            }
        }
        return nullptr;
    }

    vector<Restaurant> getAllRestaurants() const {
        return restaurants;
    }

    // UPDATE
    bool updateRestaurant(int id,const string& name,const string& location) {

        Restaurant* restaurant = getRestaurantById(id);

        if (restaurant == nullptr)
            return false;

        restaurant->setName(name);
        restaurant->setLocation(location);

        return true;
    }

    // DELETE
    bool removeRestaurant(int id) {
        for (auto it = restaurants.begin(); it != restaurants.end(); ++it) {
            if (it->getId() == id) {
                restaurants.erase(it);
                return true;
            }
        }
        return false;
    }

    // SEARCH BY LOCATION
    vector<Restaurant> searchByLocation(const string& location) const {
        vector<Restaurant> result;

        for (const auto& restaurant : restaurants) {
            if (restaurant.getLocation() == location) {
                result.push_back(restaurant);
            }
        }

        return result;
    }

    // DISPLAY
    void displayRestaurants() const {
        for (const auto& restaurant : restaurants) {
            cout << "ID: " << restaurant.getId() << endl;
            cout << "Name: " << restaurant.getName() << endl;
            cout << "Location: " << restaurant.getLocation() << endl;
            cout << "--------------------------" << endl;
        }
    }
};
RestaurantManager* RestaurantManager::instance = nullptr;
mutex RestaurantManager::mut;