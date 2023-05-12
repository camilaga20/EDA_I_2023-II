from datetime import timedelta, datetime

def contest_duration(hours=5):
    now = datetime.now()
    arrival = now + timedelta(hours=hours)
    return arrival.strftime("Contest duration until: %A %H:%M")

contest_duration()
contest_duration(1)
contest_duration(hours=1)    