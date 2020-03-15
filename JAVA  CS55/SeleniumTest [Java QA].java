import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.firefox.FirefoxDriver;



public class Demo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//selenium code-
		
		//create drive project for chrome browser
		//we will strictly implement methods of webdriver
		/* Class name = ChromeDriver,
		  
		X driver=new X(); */
		 
		 //invoke .exe file first
		System.setProperty("webdriver.gecko.driver","C:\\Science\\Selenium\\geckodriver.exe");
		
		WebDriver driver= new FirefoxDriver();
		
		driver.get("https://www.bing.com");//Hit url on the browser
		
		System.out.println(driver.getTitle());//Validate your page title is correct
		
		
		
		System.out.println(	driver.getCurrentUrl());//validate if you are landed on correct site
		
		
		//print page source
		//System.out.println(driver.getPageSource());
		
		//driver.get("http://wikileaks.org");
		
		//Method navigate
		
		driver.navigate().to("http://wikileaks.org");
		
		//driver.navigate().back();
		//driver.navigate().forward();
		
		//how to close the windows
		//driver.close();//closes current browser
		driver.quit();//closes all the browsers that opened by selenium script
		
		
		
		//Demonstrate how to login in facebook
		driver.get("https://www.facebook.com");//Hit url on the browser
		
		driver.findElement(By.id("email")).sendKeys("This is my first code");
		
		driver.findElement(By.name("pass")).sendKeys("12345");
		
		//Every object may not have ID, className or name- Xpath and CSS preferred
		
		driver.findElement(By.linkText("Forgot account?")).click();//click does the action for you
		
		
		
	}

}