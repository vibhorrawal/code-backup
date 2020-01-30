from	selenium	import	webdriver
import selenium.webdriver.support.ui as ui
import time
browser	=	webdriver.Firefox()
wait = ui.WebDriverWait(browser, 10)

browser.get('http://172.16.1.3:8002/')
time.sleep(5)
userElem	=	browser.find_element_by_id('auth_user')
userElem.send_keys('2017kucp1009') #admn no here
passwordElem	=	browser.find_element_by_id('auth_pass')
passwordElem.send_keys('elon') # password here
loginElem	=	browser.find_element_by_id('accept')
loginElem.click()
