from datetime import timedelta, datetime

def contest_duration(hours=5):    
    
    now = datetime.now()
    arrival = now + timedelta(hours=hours)
    return arrival.strftime(f"Contest {name}'s duration until: %A %H:%M")

    contest_duration("EDAI")
    contest_duration("CPCFI", hours=0.45)