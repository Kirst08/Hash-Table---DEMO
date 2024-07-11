# Hash Table Demo

This is a simple web application that demonstrates the functionality of a hash table using JavaScript and Bootstrap. The application allows you to add, remove, and update elements in the hash table, and visualizes the hash table with linked lists to handle collisions. The screen is split into two halves, with the form on the left and the hash table visualization on the right.

## Features

- **Add Elements:** Add a name (key), phone number, and age to the hash table.
- **Remove Elements:** Remove an element from the hash table by its name (key).
- **Update Elements:** Update the phone number and age of an existing element by its name (key).
- **Hash Operation Display:** Show the hashing operation performed for each key.
- **Responsive Design:** The interface is designed to be responsive and adapts to different screen sizes using Bootstrap.

## Technologies Used

- **HTML**
- **CSS (Bootstrap)**
- **JavaScript**

## How to Use

1. **Clone the Repository:**
    ```sh
    git clone https://github.com/yourusername/hash-table-demo.git
    cd hash-table-demo
    ```

2. **Open the `index.html` file in your browser:**
    ```sh
    open index.html
    ```
    or simply double-click the `index.html` file.

## Code Explanation

### HTML Structure

The HTML is divided into two main sections using Bootstrap's grid system. The left column contains the form, and the right column contains the hash table visualization.

```html
<div class="container-fluid">
    <div class="row">
        <div class="col-md-6 form-container">
            <!-- Form Elements Here -->
        </div>
        <div class="col-md-6 table-container">
            <!-- Hash Table Visualization Here -->
        </div>
    </div>
</div>
```
