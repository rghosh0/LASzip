
Pod::Spec.new do |s|
  s.name             = "laszip"
  s.version          = "2.2"
  s.summary          = "LASzip: free and lossless LiDAR compression"
  s.description      = <<-DESC
                        LASzip - a free open source product of rapidlasso GmbH - quickly turns bulky LAS files into compact LAZ files without information loss.
                       DESC
  s.homepage         = "http://www.laszip.org"
  s.license          = 'GNU LGPL 2.1'
  s.author           = {
                        "Martin Isenburg" => "martin.isenburg@rapidlasso.com",
                        "Howard Butler" => "howard@hobu.co",
                        "Michael P. Gerlek" => "mpg@flaxen.com"
  }
  s.platform     = :ios, '7.0'
  s.requires_arc = false

  s.source = { :git => 'https://github.com/mousebird/LASzip.git', :branch => 'master' }

  s.compiler_flags = '-DLASZIPDLL_EXPORTS=1 -DUNORDERED=1'

  s.public_header_files = 'include/laszip/*.h'
  s.private_header_files = 'src/*.hpp'
  s.source_files = 'src/*.{cpp,hpp,}', 'include/laszip/*.h'

end

