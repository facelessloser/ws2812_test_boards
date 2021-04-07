#include <FastLED.h>

FASTLED_USING_NAMESPACE

// FastLED "100-lines-of-code" demo reel, showing just a few 
// of the kinds of animation patterns you can quickly and easily 
// compose using FastLED.  
//
// This example also shows one easy way to define multiple 
// animations patterns and have them automatically rotate.
//
// -Mark Kriegsman, December 2014

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

//#define DATA_PIN    3
#define DATA_PIN   4 
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
//#define NUM_LEDS    60
#define NUM_LEDS    40
CRGB leds[NUM_LEDS];

//#define BRIGHTNESS          96
#define BRIGHTNESS  255
#define FRAMES_PER_SECOND  120
#define UPDATES_PER_SECOND 100

// Button code
const int buttonPin1 = 2; // the number of the pushbutton pin
int buttonState1 = 0; // variable for reading the pushbutton status
boolean buttonOne = 0;
//boolean buttonOne = 1; // TEST CODE

const int buttonPin2 = 1; // the number of the pushbutton pin
int buttonState2 = 0; // variable for reading the pushbutton status
boolean buttonTwo = 0;
//boolean buttonTwo = 1; // TEST CODE

const int buttonPin3 = 0; // the number of the pushbutton pin
int buttonState3 = 0; // variable for reading the pushbutton status
boolean buttonThree = 0;
//boolean buttonThree = 1; // TEST CODE

const int buttonPin4 = 3; // the number of the pushbutton pin
int buttonState4 = 0; // variable for reading the pushbutton status
boolean buttonFour = 0;
//boolean buttonFour = 1; // TEST CODE

// Solid colour stuff
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
//
extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void setup() {

  delay(1000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  
  // tell FastLED about the LED strip configuration
//  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
//
//  // set master brightness control
//  FastLED.setBrightness(BRIGHTNESS);

  pinMode(buttonPin1, INPUT);     
  digitalWrite(buttonPin1, HIGH); // initiate the internal pull up resistor
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW) 
  {
   buttonOne = 1;
  }

  pinMode(buttonPin2, INPUT);     
  digitalWrite(buttonPin2, HIGH); // initiate the internal pull up resistor
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == LOW) 
  {
   buttonTwo = 1;
  }

  pinMode(buttonPin3, INPUT);     
  digitalWrite(buttonPin3, HIGH); // initiate the internal pull up resistor
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 == LOW) 
  {
   buttonThree = 1;
  }

  pinMode(buttonPin4, INPUT);     
  digitalWrite(buttonPin4, HIGH); // initiate the internal pull up resistor
  buttonState4 = digitalRead(buttonPin4);
  if (buttonState4 == LOW) 
  {
   buttonFour = 1;
  }
}

uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop()
{
// Zero
  if (buttonOne == 0 && buttonTwo == 0 && buttonThree == 0 && buttonFour == 0)
  {
    CRGB white  = CRGB::White;
    currentPalette = CRGBPalette16(white);
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
  }

// One
  if (buttonOne == 1 && buttonTwo == 0 && buttonThree == 0 && buttonFour == 0)
  {
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    
    currentPalette = CRGBPalette16(green);
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
  }

// Two
  if (buttonOne == 0 && buttonTwo == 1 && buttonThree == 0 && buttonFour == 0)
  {
    CRGB red  = CHSV( HUE_RED, 255, 255);
    currentPalette = CRGBPalette16(red);
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
  }
    
// Three
  if (buttonOne == 0 && buttonTwo == 0 && buttonThree == 1 && buttonFour == 0 )
  {
    CRGB blue  = CHSV( HUE_BLUE, 255, 255);
    currentPalette = CRGBPalette16(blue);
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
  }

// Four
  if (buttonOne == 0 && buttonTwo == 0 && buttonThree == 0 && buttonFour == 1)
  {
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    currentPalette = CRGBPalette16(purple);
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors( startIndex);
    FastLED.show();
  }

  if (buttonOne == 1 && buttonTwo == 1 && buttonThree == 0 && buttonFour == 0)
  {
    SetupRedAndBluePalette();
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    
    FillLEDsFromPaletteColors( startIndex);
    
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }

  if (buttonOne == 1 && buttonTwo == 1 && buttonThree == 1 && buttonFour == 0)
  {
    pride();
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }

  if (buttonOne == 1 && buttonTwo == 1 && buttonThree == 1 && buttonFour == 1)
  {
    sinelon();
    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
    // do some periodic updates
    EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  }
}

// Sinelon stuff
void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

// Pride stuff
// This function draws rainbows with an ever-changing,
// widely-varying set of parameters.
void pride() 
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor = CHSV( hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend( leds[pixelnumber], newcolor, 64);
  }
}

// Solid color stuff
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}
// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette()
{
    for( int i = 0; i < 16; i++) {
        currentPalette[i] = CHSV( random8(), 255, random8());
    }
}

void SetupRedAndBluePalette()
{
    CRGB blue  = CHSV( HUE_BLUE, 255, 255);
    CRGB red  = CHSV( HUE_RED, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   red,  red,  blue, blue,
                                   blue, blue, red,  red,
                                   red,  red,  blue, blue,
                                   blue, blue, red,  red );
}
