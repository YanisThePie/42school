class ShowcaseController < ApplicationController
  skip_before_action :authorize
  def Home
      render :layout => "home"
  end
  def Video
    render :layout => false
  def Idea
  end
  def Legend
  end
end
end
