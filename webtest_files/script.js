document.addEventListener("DOMContentLoaded", function() {
    // Connect to the brightness slider
    var brightnessSlider = document.getElementById("brightness");
  
    // Set initial brightness value
    var brightnessValue = brightnessSlider.value;
  
    // Function to update the brightness of all LEDs
    function updateBrightness() {
      var brightness = brightnessSlider.value;
      // Send brightness value to the server or update the LEDs directly
      // depending on how your system is set up
      // Example using jQuery:
      // $.post("/setBrightness", { brightness: brightness });
  
      // Update brightnessValue variable
      brightnessValue = brightness;
    }
  
    // Event listener for the brightness slider
    brightnessSlider.addEventListener("input", updateBrightness);
  
    // Function to handle mode selection
    function handleModeSelection(mode) {
      // Send the selected mode to the server or control the LEDs directly
      // depending on how your system is set up
      // Example using jQuery:
      // $.post("/setMode", { mode: mode });
  
      // Perform different actions based on the selected mode
      if (mode === "larson-scanner") {
        // Larson Scanner mode
        // Add your code here
      } else if (mode === "psi-mode") {
        // PSI Mode
        // Add your code here
      } else if (mode === "off") {
        // Turn off the LEDs
        // Add your code here
      }
    }
  
    // Event listener for mode selection buttons
    var modeButtons = document.querySelectorAll("#modes button");
    modeButtons.forEach(function(button) {
      button.addEventListener("click", function() {
        var mode = this.id;
        handleModeSelection(mode);
      });
    });
  });
  