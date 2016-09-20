//hold variables
var city = '';
var state ='';
var APIkey = '2ac0a571e7c93cbb';

//insert all the data into the divs
function loadWeather(unicorn){
	console.log(unicorn);

	if(unicorn.response.error){
		alert(unicorn.response.error.description);//to access the object inside of it,you use.
		return;
	}

	var thisCity = unicorn.current_observation.display_location.city;
	var temperature = unicorn.current_observation.temp_c;
	var weather = unicorn.current_observation.weather;
	var icon = unicorn.current_observation.icon_url;

	$('#temperature').text(temperature);
	$('#weather').html(weather);
	$('#weatherIcon').html('<img src="'+ icon +'">');

	// if(thisCity == 'New York'){
	// 	$('#currentCity').
	// }

}

//get weather data
function getWeather(){
	var myUrl = "http://api.wunderground.com/api/" + APIkey +"/conditions/q/" + state + "/" + city +".json"

	$.ajax({
		url:myUrl,
		dataType:"jsonp",
		success:function(response){
			// console.log(response);
			loadWeather(response);
		},
		error:function(response){
			alert('Try again.');
		}
	})
}
//pass city/state data when submit is clicked
function setLocation(){
	city = $('#currentCity').val();//get value from currentCity input
	state = $('#currentState').val();//ger value from currentCity input

	if(city == null|| city ==''){
		alert('You need to choose a city')
	}

	console.log("Getting weather for: " + city +","+state);
	getWeather();
}

//init
function init(){
	console.log("Hello");

	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	});
};
//run on load
$(document).ready(function(){
	init();
});