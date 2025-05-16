
	$(document).ready(function() {
		$("#container").css("opacity",1);
		
		$(".content_fx").animate({
			opacity: 1
		}, 1000, function() {
		// Animation complete.
		});
	});
		
						
	$(window).bind('load resize',function(){
		
			if($("#container").width() >= 1177){
				$(".example").css("overflow-y","hidden");
			}
			else{
				$(".example").css("overflow-y","auto");
			}
		
	});	
	
	$("#header").height($(".menu .heading").outerHeight());
	$("#logo_container").css("padding-top",($("#header").height()-$(".logo").outerHeight())/2);
	
	$(".section_heading_arrow").css("top",(($(".section .heading").innerHeight() - $(".section_heading_arrow").height())/2));
	$(".section_arrow").css("top", (($(".section .item").innerHeight() - $(".section_arrow").height())/2));
		
	if(tips){
		$(".note").css("display","inline-block");
	}
	else{
		$(".note").css("display","none");
	}

	if(aux == "Extras_Tips"){
	
		$("#"+aux).find("a").css("color","white");
		
		$("#"+aux).find("a").css("background-color","rgb(244,161,59)"); /* Old browsers */
		$("#"+aux).find("a").css("background","-moz-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* FF3.6+ */
		$("#"+aux).find("a").css("background","-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(184,64,45,1)), color-stop(100%,rgba(244,161,59,1)))"); /* Chrome,Safari4+ */
		$("#"+aux).find("a").css("background","-webkit-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Chrome10+,Safari5.1+ */
		$("#"+aux).find("a").css("background","-o-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Opera 11.10+ */
		$("#"+aux).find("a").css("background","-ms-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* IE10+ */
		$("#"+aux).find("a").css("background","linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* W3C */
		$("#"+aux).find("a").css("filter","progid:DXImageTransform.Microsoft.gradient( startColorstr='#b8402d', endColorstr='#f4a13b',GradientType=0 )"); /* IE6-9 */
	
	}
	
	else if(aux != ""){

		$("#"+aux).parents(".menu").find(".heading").css("color","white");
		
		$("#"+aux).parents(".menu").find(".heading").css("background-color","rgb(244,161,59)"); /* Old browsers */
		$("#"+aux).parents(".menu").find(".heading").css("background","-moz-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* FF3.6+ */
		$("#"+aux).parents(".menu").find(".heading").css("background","-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(184,64,45,1)), color-stop(100%,rgba(244,161,59,1)))"); /* Chrome,Safari4+ */
		$("#"+aux).parents(".menu").find(".heading").css("background","-webkit-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Chrome10+,Safari5.1+ */
		$("#"+aux).parents(".menu").find(".heading").css("background","-o-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Opera 11.10+ */
		$("#"+aux).parents(".menu").find(".heading").css("background","-ms-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* IE10+ */
		$("#"+aux).parents(".menu").find(".heading").css("background","linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* W3C */
		$("#"+aux).parents(".menu").find(".heading").css("filter","progid:DXImageTransform.Microsoft.gradient( startColorstr='#b8402d', endColorstr='#f4a13b',GradientType=0 )"); /* IE6-9 */
		
		$("#"+aux).find("a").css({
			"background-color" : "rgb(255,255,255)",
			"background-color" : "rgba(255,255,255,0.75)",
			"color" : "black"
		});
		
	}
	
	else if(example != "" && section != ""){	
	
		$("#"+example).find(".icon").attr("src","Images/"+example+"_Icon_Selected.png");

		$("#"+example).find(".tab").css("background-color","#4b7aad"); /* Really old browsers */
		$("#"+example).find(".tab").css("background-color","rgba(255,255,255,0.25)"); /* Old browsers */
		$("#"+example).find(".tab").css("background","-moz-linear-gradient(top,  rgba(255,255,255,0) 0%, rgba(255,255,255,0.25) 100%)"); /* FF3.6+ */
		$("#"+example).find(".tab").css("background","-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(255,255,255,0)), color-stop(100%,rgba(255,255,255,0.25)))"); /* Chrome,Safari4+ */
		$("#"+example).find(".tab").css("background","-webkit-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* Chrome10+,Safari5.1+ */
		$("#"+example).find(".tab").css("background","-o-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* Opera 11.10+ */
		$("#"+example).find(".tab").css("background","-ms-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* IE10+ */
		$("#"+example).find(".tab").css("background","linear-gradient(to bottom,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* W3C */
			
		$("#"+section).find("a").css("background-color","#4b7aad"); /* Really old browsers */
		$("#"+section).find("a").css("background-color","rgba(255,255,255,0.2)"); /* Old browsers */
		$("#"+section).find("a").css("background","-moz-linear-gradient(left,  rgba(255,255,255,0) 0%, rgba(255,255,255,0.2) 100%)"); /* FF3.6+ */
		$("#"+section).find("a").css("background","-webkit-gradient(linear, left top, right top, color-stop(0%,rgba(255,255,255,0)), color-stop(100%,rgba(255,255,255,0.2)))"); /* Chrome,Safari4+ */
		$("#"+section).find("a").css("background","-webkit-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* Chrome10+,Safari5.1+ */
		$("#"+section).find("a").css("background","-o-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* Opera 11.10+ */
		$("#"+section).find("a").css("background","-ms-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* IE10+ */
		$("#"+section).find("a").css("background","linear-gradient(to right,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* W3C */
	
	}	
	
	var bg; 
	var color; 
	var src;

	$(".example .item").hover(
		function(){
			if($(this).attr("id") != example){
			
				bg = $(this).find(".tab").css("background");
				color = $(this).find(".tab").css("color");
				src =  $(this).find(".icon").attr("src");

				$(this).find(".tab").css("background-color","#4b7aad"); /* Really old browsers */
				$(this).find(".tab").css("background-color","rgba(255,255,255,0.25)"); /* Old browsers */
				$(this).find(".tab").css("background","-moz-linear-gradient(top,  rgba(255,255,255,0) 0%, rgba(255,255,255,0.25) 100%)"); /* FF3.6+ */
				$(this).find(".tab").css("background","-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(255,255,255,0)), color-stop(100%,rgba(255,255,255,0.25)))"); /* Chrome,Safari4+ */
				$(this).find(".tab").css("background","-webkit-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* Chrome10+,Safari5.1+ */
				$(this).find(".tab").css("background","-o-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* Opera 11.10+ */
				$(this).find(".tab").css("background","-ms-linear-gradient(top,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* IE10+ */
				$(this).find(".tab").css("background","linear-gradient(to bottom,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.25) 100%)"); /* W3C */

				$(this).find(".icon").attr("src","Images/"+$(this).attr("id")+"_Icon_Selected.png");
				
			}
		},
		function(){
		
			if($(this).attr("id") != example){
				$(this).find(".tab").css({
					"background" : bg ,
					"color" : color
				});
				$(this).find(".icon").attr("src",src);
			}
			
		}
	);

	$(".section .item").hover(
		function(){
			if($(this).attr("id") != section){
			
				bg = $(this).find("a").css("background");
				color = $(this).find("a").css("color");
				
				$(this).find("a").css("background-color","#4b7aad"); /* Really old browsers */
				$(this).find("a").css("background-color","rgba(255,255,255,0.2)"); /* Old browsers */
				$(this).find("a").css("background","-moz-linear-gradient(left,  rgba(255,255,255,0) 0%, rgba(255,255,255,0.2) 100%)"); /* FF3.6+ */
				$(this).find("a").css("background","-webkit-gradient(linear, left top, right top, color-stop(0%,rgba(255,255,255,0)), color-stop(100%,rgba(255,255,255,0.2)))"); /* Chrome,Safari4+ */
				$(this).find("a").css("background","-webkit-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* Chrome10+,Safari5.1+ */
				$(this).find("a").css("background","-o-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* Opera 11.10+ */
				$(this).find("a").css("background","-ms-linear-gradient(left,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* IE10+ */
				$(this).find("a").css("background","linear-gradient(to right,  rgba(255,255,255,0) 0%,rgba(255,255,255,0.2) 100%)"); /* W3C */
			}
		},
		function(){
		
			if($(this).attr("id") != section){
				$(this).find("a").css({
					"background" : bg ,
					"color" : color
				});
			}
			
		}
	);

	$(".menu").hover(
		function(){ 
				$(this).find(".expand").css("display","inline-block");
		},
		function(){
				$(this).find(".expand").css("display","none");
		}
	);
	
	var bg2;
	var color2;
	var filter2;
	
	$(".menu").hover(
		function(){ 
		
			bg2 = $(this).find(".heading").css("background");
			filter2 = $(this).find(".heading").css("filter");
			color2 = $(this).find(".heading").css("color");
			
			$(this).find(".heading").css("color","white");
			
			$(this).find(".heading").css("background-color","rgb(244,161,59)"); /* Old browsers */
			$(this).find(".heading").css("background","-moz-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* FF3.6+ */
			$(this).find(".heading").css("background","-webkit-gradient(linear, left top, left bottom, color-stop(0%,rgba(184,64,45,1)), color-stop(100%,rgba(244,161,59,1)))"); /* Chrome,Safari4+ */
			$(this).find(".heading").css("background","-webkit-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Chrome10+,Safari5.1+ */
			$(this).find(".heading").css("background","-o-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* Opera 11.10+ */
			$(this).find(".heading").css("background","-ms-linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* IE10+ */
			$(this).find(".heading").css("background","linear-gradient(top, rgba(184,64,45,1) 0%, rgba(244,161,59,1) 100%)"); /* W3C */
			$(this).find(".heading").css("filter","progid:DXImageTransform.Microsoft.gradient( startColorstr='#b8402d', endColorstr='#f4a13b',GradientType=0 )"); /* IE6-9 */
			
		},
		function(){
		
			$(this).find(".heading").css("background",bg2);
			$(this).find(".heading").css("filter",filter2);
			$(this).find(".heading").css("color",color2);
			
		}
	);
	
	$(".menu .item").hover(
		function(){
		
			bg = $(this).find("a").css("background-color");
			color = $(this).find("a").css("color");
			$(this).find("a").css({
				"background-color" : "rgb(255,255,255)",
				"background-color" : "rgba(255,255,255,0.75)",
				"color"	: "black"
			});
			
		},
		function(){
		
			$(this).find("a").css({
				"background-color" : bg,
				"color" : color
			});
			
		}
	);

	$("#CTMS_logo").hover(
	function(){
	
			src =  $(this).attr("src");
			$(this).attr("src","Images/CTMS_logo_selected.png");
			
	},
	function(){
	
			$(this).attr("src",src);
			
	});
	

	