// Name: Kenny Zhou
// Date : 9/20/25
#pragma once

#include <vector>
#include <algorithm>
#include <iterator>
#include "Inventory.hpp"
#include <string>

class Player {
    private:
        Inventory inventory_; // An Inventory object representing the inventory data of this player
        std::string name_; // The name of the player
    public:
        /**
        * @brief Constructs a Player with the given identifier.
        * @param name A const. string reference to be the player name
        * @param inventory A const ref. to an Inventory to copy
        * and setup a Player's inventory_ member. If none provided,
        * default value of a default constructed Inventory
        */
        Player(const std::string& name, const Inventory& inventory = Inventory());

        /**
        * @brief Gets the name of the Player
        * @return The string value stored in name
        */
        std::string getName() const;

        /**
        * @brief Exposes a reference to interact with the Player's Inventory.
        * @return A reference to the Player's inventory_
        * @note Since we allow modification to this reference, this function
        * is NOT declared const.
        */
        Inventory& getInventoryRef(); 

        /**
        * @brief Copy constructor for the Player class.
        * @param rhs A const l-value ref. to the Player object to copy.
        * @post Creates a deep copy of `rhs`
        */
        Player(const Player& rhs);

        /**
        * @brief Move constructor for the Player class.
        * @param rhs An r-value ref. to a Player object to move from.
        * @post Transfers ownership of resources from `rhs`
        * to the newly constructed Player object *using move semantics*
        */
        Player(Player&& rhs);

        /**
        * @brief Copy assignment operator for the Player class.
        * @param rhs A const l-value ref. to the Player object to copy.
        * @return A reference to the updated Player object.
        * @post Performs a deep copy of `rhs`, including
        * re-allocating the equipped item and copying the Inventory.
        */
        Player& operator=(const Player& rhs);

        /**
        * @brief Move assignment operator for the Player class.
        * @param rhs An r-value ref. to a Player object to move from.
        * @return A reference to the updated Player object.
        * @post Transfers ownership of member resources from `rhs`
        * to the updated Player object *using move semantics*
        */
        Player& operator=(Player&& rhs);

        /**
        * @brief Destructor for the Player class
        * Since we have no dynamic memory as private members,
        * we rely on the default destructor.
        * NOTE: This means, we do NOT need to provide our own implementation.
        */
        ~Player() = default;
};