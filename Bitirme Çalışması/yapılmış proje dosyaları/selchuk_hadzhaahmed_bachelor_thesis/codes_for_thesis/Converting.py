import pandas as pd
import csv
import re


dataset = pd.read_csv('PlayerAttributeData11.csv')

#Accleration
dataset["Acceleration"] = dataset.Acceleration.str.replace('[+]', '.')
dataset["Acceleration"] = dataset.Acceleration.str.replace('[-]', '.')
dataset.loc[dataset.Acceleration.str.contains('.') == True, "Acceleration"] = pd.to_numeric(dataset.loc[dataset.Acceleration.str.contains('.') == True, "Acceleration"], downcast='signed')

#Aggression
dataset["Aggression"] = dataset.Aggression.str.replace('[+]', '.')
dataset["Aggression"] = dataset.Aggression.str.replace('[-]', '.')
dataset.loc[dataset.Aggression.str.contains('.') == True, "Aggression"] = pd.to_numeric(dataset.loc[dataset.Aggression.str.contains('.') == True, "Aggression"], downcast='signed')

#Agility
dataset["Agility"] = dataset.Agility.str.replace('[+]', '.')
dataset["Agility"] = dataset.Agility.str.replace('[-]', '.')
dataset.loc[dataset.Agility.str.contains('.') == True, "Agility"] = pd.to_numeric(dataset.loc[dataset.Agility.str.contains('.') == True, "Agility"], downcast='signed')

#Balance
dataset["Balance"] = dataset.Balance.str.replace('[+]', '.')
dataset["Balance"] = dataset.Balance.str.replace('[-]', '.')
dataset.loc[dataset.Balance.str.contains('.') == True, "Balance"] = pd.to_numeric(dataset.loc[dataset.Balance.str.contains('.') == True, "Balance"], downcast='signed')

#Ballcontrol
dataset["Ballcontrol"] = dataset.Ballcontrol.str.replace('[+]', '.')
dataset["Ballcontrol"] = dataset.Ballcontrol.str.replace('[-]', '.')
dataset.loc[dataset.Ballcontrol.str.contains('.') == True, "Ballcontrol"] = pd.to_numeric(dataset.loc[dataset.Ballcontrol.str.contains('.') == True, "Ballcontrol"], downcast='signed')

#Composure
dataset["Composure"] = dataset.Composure.str.replace('[+]', '.')
dataset["Composure"] = dataset.Composure.str.replace('[-]', '.')
dataset.loc[dataset.Composure.str.contains('.') == True, "Composure"] = pd.to_numeric(dataset.loc[dataset.Composure.str.contains('.') == True, "Composure"], downcast='signed')

#Crossing
dataset["Crossing"] = dataset.Crossing.str.replace('[+]', '.')
dataset["Crossing"] = dataset.Crossing.str.replace('[-]', '.')
dataset.loc[dataset.Crossing.str.contains('.') == True, "Crossing"] = pd.to_numeric(dataset.loc[dataset.Crossing.str.contains('.') == True, "Crossing"], downcast='signed')

#Curve
dataset["Curve"] = dataset.Curve.str.replace('[+]', '.')
dataset["Curve"] = dataset.Curve.str.replace('[-]', '.')
dataset.loc[dataset.Curve.str.contains('.') == True, "Curve"] = pd.to_numeric(dataset.loc[dataset.Curve.str.contains('.') == True, "Curve"], downcast='signed')

#Dribbling
dataset["Dribbling"] = dataset.Dribbling.str.replace('[+]', '.')
dataset["Dribbling"] = dataset.Dribbling.str.replace('[-]', '.')
dataset.loc[dataset.Dribbling.str.contains('.') == True, "Dribbling"] = pd.to_numeric(dataset.loc[dataset.Dribbling.str.contains('.') == True, "Dribbling"], downcast='signed')

#Finishing
dataset["Finishing"] = dataset.Finishing.str.replace('[+]', '.')
dataset["Finishing"] = dataset.Finishing.str.replace('[-]', '.')
dataset.loc[dataset.Finishing.str.contains('.') == True, "Finishing"] = pd.to_numeric(dataset.loc[dataset.Finishing.str.contains('.') == True, "Finishing"], downcast='signed')

#Freekickaccuracy
dataset["Freekickaccuracy"] = dataset.Freekickaccuracy.str.replace('[+]', '.')
dataset["Freekickaccuracy"] = dataset.Freekickaccuracy.str.replace('[-]', '.')
dataset.loc[dataset.Freekickaccuracy.str.contains('.') == True, "Freekickaccuracy"] = pd.to_numeric(dataset.loc[dataset.Freekickaccuracy.str.contains('.') == True, "Freekickaccuracy"], downcast='signed')

#GKdiving
dataset["GKdiving"] = dataset.GKdiving.str.replace('[+]', '.')
dataset["GKdiving"] = dataset.GKdiving.str.replace('[-]', '.')
dataset.loc[dataset.GKdiving.str.contains('.') == True, "GKdiving"] = pd.to_numeric(dataset.loc[dataset.GKdiving.str.contains('.') == True, "GKdiving"], downcast='signed')

#GKhandling
dataset["GKhandling"] = dataset.GKhandling.str.replace('[+]', '.')
dataset["GKhandling"] = dataset.GKhandling.str.replace('[-]', '.')
dataset.loc[dataset.GKhandling.str.contains('.') == True, "GKhandling"] = pd.to_numeric(dataset.loc[dataset.GKhandling.str.contains('.') == True, "GKhandling"], downcast='signed')

#GKkicking
dataset["GKkicking"] = dataset.GKkicking.str.replace('[+]', '.')
dataset["GKkicking"] = dataset.GKkicking.str.replace('[-]', '.')
dataset.loc[dataset.GKkicking.str.contains('.') == True, "GKkicking"] = pd.to_numeric(dataset.loc[dataset.GKkicking.str.contains('.') == True, "GKkicking"], downcast='signed')

#GKpositioning
dataset["GKpositioning"] = dataset.GKpositioning.str.replace('[+]', '.')
dataset["GKpositioning"] = dataset.GKpositioning.str.replace('[-]', '.')
dataset.loc[dataset.GKpositioning.str.contains('.') == True, "GKpositioning"] = pd.to_numeric(dataset.loc[dataset.GKpositioning.str.contains('.') == True, "GKpositioning"], downcast='signed')

#GKreflexes
dataset["GKreflexes"] = dataset.GKreflexes.str.replace('[+]', '.')
dataset["GKreflexes"] = dataset.GKreflexes.str.replace('[-]', '.')
dataset.loc[dataset.GKreflexes.str.contains('.') == True, "GKreflexes"] = pd.to_numeric(dataset.loc[dataset.GKreflexes.str.contains('.') == True, "GKreflexes"], downcast='signed')

#Headingaccuracy
dataset["Headingaccuracy"] = dataset.Headingaccuracy.str.replace('[+]', '.')
dataset["Headingaccuracy"] = dataset.Headingaccuracy.str.replace('[-]', '.')
dataset.loc[dataset.Headingaccuracy.str.contains('.') == True, "Headingaccuracy"] = pd.to_numeric(dataset.loc[dataset.Headingaccuracy.str.contains('.') == True, "Headingaccuracy"], downcast='signed')

#Interceptions
dataset["Interceptions"] = dataset.Interceptions.str.replace('[+]', '.')
dataset["Interceptions"] = dataset.Interceptions.str.replace('[-]', '.')
dataset.loc[dataset.Interceptions.str.contains('.') == True, "Interceptions"] = pd.to_numeric(dataset.loc[dataset.Interceptions.str.contains('.') == True, "Interceptions"], downcast='signed')

#Jumping
dataset["Jumping"] = dataset.Jumping.str.replace('[+]', '.')
dataset["Jumping"] = dataset.Jumping.str.replace('[-]', '.')
dataset.loc[dataset.Jumping.str.contains('.') == True, "Jumping"] = pd.to_numeric(dataset.loc[dataset.Jumping.str.contains('.') == True, "Jumping"], downcast='signed')

#Longpassing
dataset["Longpassing"] = dataset.Longpassing.str.replace('[+]', '.')
dataset["Longpassing"] = dataset.Longpassing.str.replace('[-]', '.')
dataset.loc[dataset.Longpassing.str.contains('.') == True, "Longpassing"] = pd.to_numeric(dataset.loc[dataset.Longpassing.str.contains('.') == True, "Longpassing"], downcast='signed')

#Longshots
dataset["Longshots"] = dataset.Longshots.str.replace('[+]', '.')
dataset["Longshots"] = dataset.Longshots.str.replace('[-]', '.')
dataset.loc[dataset.Longshots.str.contains('.') == True, "Longshots"] = pd.to_numeric(dataset.loc[dataset.Longshots.str.contains('.') == True, "Longshots"], downcast='signed')

#Marking
dataset["Marking"] = dataset.Marking.str.replace('[+]', '.')
dataset["Marking"] = dataset.Marking.str.replace('[-]', '.')
dataset.loc[dataset.Marking.str.contains('.') == True, "Marking"] = pd.to_numeric(dataset.loc[dataset.Marking.str.contains('.') == True, "Marking"], downcast='signed')

#Penalties
dataset["Penalties"] = dataset.Penalties.str.replace('[+]', '.')
dataset["Penalties"] = dataset.Penalties.str.replace('[-]', '.')
dataset.loc[dataset.Penalties.str.contains('.') == True, "Penalties"] = pd.to_numeric(dataset.loc[dataset.Penalties.str.contains('.') == True, "Penalties"], downcast='signed')

#Positioning
dataset["Positioning"] = dataset.Positioning.str.replace('[+]', '.')
dataset["Positioning"] = dataset.Positioning.str.replace('[-]', '.')
dataset.loc[dataset.Positioning.str.contains('.') == True, "Positioning"] = pd.to_numeric(dataset.loc[dataset.Positioning.str.contains('.') == True, "Positioning"], downcast='signed')

#Reactions
dataset["Reactions"] = dataset.Reactions.str.replace('[+]', '.')
dataset["Reactions"] = dataset.Reactions.str.replace('[-]', '.')
dataset.loc[dataset.Reactions.str.contains('.') == True, "Reactions"] = pd.to_numeric(dataset.loc[dataset.Reactions.str.contains('.') == True, "Reactions"], downcast='signed')

#Shortpassing
dataset["Shortpassing"] = dataset.Shortpassing.str.replace('[+]', '.')
dataset["Shortpassing"] = dataset.Shortpassing.str.replace('[-]', '.')
dataset.loc[dataset.Shortpassing.str.contains('.') == True, "Shortpassing"] = pd.to_numeric(dataset.loc[dataset.Shortpassing.str.contains('.') == True, "Shortpassing"], downcast='signed')

#Shotpower
dataset["Shotpower"] = dataset.Shotpower.str.replace('[+]', '.')
dataset["Shotpower"] = dataset.Shotpower.str.replace('[-]', '.')
dataset.loc[dataset.Shotpower.str.contains('.') == True, "Shotpower"] = pd.to_numeric(dataset.loc[dataset.Shotpower.str.contains('.') == True, "Shotpower"], downcast='signed')

#Slidingtackle
dataset["Slidingtackle"] = dataset.Slidingtackle.str.replace('[+]', '.')
dataset["Slidingtackle"] = dataset.Slidingtackle.str.replace('[-]', '.')
dataset.loc[dataset.Slidingtackle.str.contains('.') == True, "Slidingtackle"] = pd.to_numeric(dataset.loc[dataset.Slidingtackle.str.contains('.') == True, "Slidingtackle"], downcast='signed')

#Sprintspeed
dataset["Sprintspeed"] = dataset.Sprintspeed.str.replace('[+]', '.')
dataset["Sprintspeed"] = dataset.Sprintspeed.str.replace('[-]', '.')
dataset.loc[dataset.Sprintspeed.str.contains('.') == True, "Sprintspeed"] = pd.to_numeric(dataset.loc[dataset.Sprintspeed.str.contains('.') == True, "Sprintspeed"], downcast='signed')

#Stamina
dataset["Stamina"] = dataset.Stamina.str.replace('[+]', '.')
dataset["Stamina"] = dataset.Stamina.str.replace('[-]', '.')
dataset.loc[dataset.Stamina.str.contains('.') == True, "Stamina"] = pd.to_numeric(dataset.loc[dataset.Stamina.str.contains('.') == True, "Stamina"], downcast='signed')

#Standingtackle
dataset["Standingtackle"] = dataset.Standingtackle.str.replace('[+]', '.')
dataset["Standingtackle"] = dataset.Standingtackle.str.replace('[-]', '.')
dataset.loc[dataset.Standingtackle.str.contains('.') == True, "Standingtackle"] = pd.to_numeric(dataset.loc[dataset.Standingtackle.str.contains('.') == True, "Standingtackle"], downcast='signed')

#Strength
dataset["Strength"] = dataset.Strength.str.replace('[+]', '.')
dataset["Strength"] = dataset.Strength.str.replace('[-]', '.')
dataset.loc[dataset.Strength.str.contains('.') == True, "Strength"] = pd.to_numeric(dataset.loc[dataset.Strength.str.contains('.') == True, "Strength"], downcast='signed')

#Vision
dataset["Vision"] = dataset.Vision.str.replace('[+]', '.')
dataset["Vision"] = dataset.Vision.str.replace('[-]', '.')
dataset.loc[dataset.Vision.str.contains('.') == True, "Vision"] = pd.to_numeric(dataset.loc[dataset.Vision.str.contains('.') == True, "Vision"], downcast='signed')

#Volleys
dataset["Volleys"] = dataset.Volleys.str.replace('[+]', '.')
dataset["Volleys"] = dataset.Volleys.str.replace('[-]', '.')
dataset.loc[dataset.Volleys.str.contains('.') == True, "Volleys"] = pd.to_numeric(dataset.loc[dataset.Volleys.str.contains('.') == True, "Volleys"], downcast='signed')

#Data updating
dataset.to_csv('PlayerAttributeData11_updated.csv')
