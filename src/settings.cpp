#include "settings.h"
#include "files.h"
#include <string>
#include <sstream>
#include "QStringList"

Settings::Settings()
{
    Files fileReader;
    std::string settingsStr = fileReader.read(".objGUI.conf");
    QStringList settingsList = QString::fromStdString(settingsStr).split("\n", QString::SkipEmptyParts);

    if (settingsList.length() == 3){
        // Set values to saved settings
        // Note: toInt returns 0 if conversion fails
        windowWidth = settingsList.at(0).toInt();
        windowHeight = settingsList.at(1).toInt();
        syntax = settingsList.at(2);

    } else {
        // Default Values
        windowWidth = 1000;
        windowHeight = 600;
        syntax = "intel";
    }
}

void Settings::saveSettings(){
    // Build settings file string
    std::ostringstream oss;
    oss << getWindowWidth() << "\n";
    oss << getWindowHeight() << "\n";
    oss << getSyntax().toStdString() << "\n";

    // Write Settings To File
    Files fileWriter;
    fileWriter.write(".objGUI.conf", oss.str());

}

// Set Values
void Settings::setWindowWidth(int w){
    windowWidth = w;
}
void Settings::setWindowHeight(int h){
    windowHeight = h;
}
void Settings::setSyntax(QString s){
    // TODO: Add validation
    syntax = s;
}

// Get Values
int Settings::getWindowWidth(){
    return windowWidth;
}
int Settings::getWindowHeight(){
    return windowHeight;
}
QString Settings::getSyntax(){
    return syntax;
}
