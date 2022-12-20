import eel

eel.init('web')

# Two tasks,
# 1. Send data to UI (User Interface).
# 2. Receive data from UI (User Interface).

# Receiving Data
@eel.expose
def get_data(value):
    print('%s' % value)
    
# Sending Data
# eel.send_data("1")


eel.start('index.html')


