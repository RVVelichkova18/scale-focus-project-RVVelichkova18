USE [master]
GO
/****** Object:  Database [ManagementSystemProject]    Script Date: 7/13/2021 2:18:15 PM ******/
CREATE DATABASE [ManagementSystemProject]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'ManagementSystemProject', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\ManagementSystemProject.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'ManagementSystemProject_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\ManagementSystemProject_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [ManagementSystemProject].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [ManagementSystemProject] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET ARITHABORT OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [ManagementSystemProject] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [ManagementSystemProject] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET  DISABLE_BROKER 
GO
ALTER DATABASE [ManagementSystemProject] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [ManagementSystemProject] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [ManagementSystemProject] SET  MULTI_USER 
GO
ALTER DATABASE [ManagementSystemProject] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [ManagementSystemProject] SET DB_CHAINING OFF 
GO
ALTER DATABASE [ManagementSystemProject] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [ManagementSystemProject] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [ManagementSystemProject] SET DELAYED_DURABILITY = DISABLED 
GO
USE [ManagementSystemProject]
GO
/****** Object:  Table [dbo].[Projects]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Projects](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime2](0) NULL,
	[IdCreator] [int] NULL,
	[DateLastChange] [datetime2](0) NULL,
	[IdLastChange] [int] NULL,
	[isDeleted] [bit] NOT NULL,
 CONSTRAINT [PK_Projects] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ProjectsTeams]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProjectsTeams](
	[ProjectId] [int] NOT NULL,
	[TeamId] [int] NOT NULL,
 CONSTRAINT [PK_ProjectsTeams] PRIMARY KEY CLUSTERED 
(
	[ProjectId] ASC,
	[TeamId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tasks]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tasks](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[ProjectId] [int] NOT NULL,
	[UserId] [int] NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](50) NOT NULL,
	[Status] [tinyint] NOT NULL,
	[DateOfCreation] [datetime] NOT NULL,
	[IdCreator] [int] NULL,
	[DateLastChange] [datetime] NOT NULL,
	[IdLastChange] [int] NULL,
	[isDeleted] [bit] NOT NULL,
 CONSTRAINT [PK_Tasks] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Teams]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Teams](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime] NOT NULL,
	[IdCreator] [int] NULL,
	[DateLastChange] [datetime] NOT NULL,
	[IdLastChange] [int] NULL,
	[isDeleted] [bit] NOT NULL,
 CONSTRAINT [PK_Teams] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Users]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Username] [nvarchar](50) NOT NULL,
	[Password] [nvarchar](50) NOT NULL,
	[FirstName] [nvarchar](50) NOT NULL,
	[LastName] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime2](0) NULL,
	[IdCreator] [int] NULL,
	[DateOfLastChange] [datetime2](0) NULL,
	[IdLastChange] [int] NULL,
	[isAdmin] [bit] NULL,
	[isDeleted] [bit] NOT NULL,
 CONSTRAINT [PK_Users] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[UsersTeams]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UsersTeams](
	[UserId] [int] NOT NULL,
	[TeamId] [int] NOT NULL,
 CONSTRAINT [PK_UsersTeams] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[TeamId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WorkLog]    Script Date: 7/13/2021 2:18:15 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WorkLog](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[TaskId] [int] NOT NULL,
	[UserId] [int] NOT NULL,
	[Time] [datetime2](0) NOT NULL,
	[Date] [datetime2](0) NOT NULL,
	[isDeleted] [bit] NOT NULL,
 CONSTRAINT [PK_WorkLog] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Users] ON 
GO
INSERT [dbo].[Users] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdCreator], [DateOfLastChange], [IdLastChange], [isAdmin], [isDeleted]) VALUES (1, N'admin', N'adminpass', N'Radina', N'Velichkova', CAST(N'2021-07-08T09:35:51.0000000' AS DateTime2), 1, CAST(N'2021-07-08T15:54:52.0000000' AS DateTime2), 1, 1, 0)
GO
INSERT [dbo].[Users] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdCreator], [DateOfLastChange], [IdLastChange], [isAdmin], [isDeleted]) VALUES (2, N'kolev', N'kolevpass', N'Kole', N'Kolev', CAST(N'2021-07-08T09:40:15.0000000' AS DateTime2), 1, CAST(N'2021-07-08T17:10:12.0000000' AS DateTime2), 1, 0, 0)
GO
INSERT [dbo].[Users] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdCreator], [DateOfLastChange], [IdLastChange], [isAdmin], [isDeleted]) VALUES (3, N'sandonova', N'sandonovapass', N'Stanislava', N'Andonova', CAST(N'2021-07-08T09:41:13.0000000' AS DateTime2), 1, CAST(N'2021-07-08T15:54:52.0000000' AS DateTime2), 1, 0, 0)
GO
INSERT [dbo].[Users] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdCreator], [DateOfLastChange], [IdLastChange], [isAdmin], [isDeleted]) VALUES (4, N'skolev', N'skolevpass', N'Stoqn', N'Kolew', CAST(N'2021-07-08T15:54:52.0000000' AS DateTime2), 1, CAST(N'2021-07-08T15:54:52.0000000' AS DateTime2), 1, 0, 0)
GO
INSERT [dbo].[Users] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdCreator], [DateOfLastChange], [IdLastChange], [isAdmin], [isDeleted]) VALUES (5, N'iiliev', N'iilievpass', N'Ilko', N'Iliev', CAST(N'2021-07-12T16:53:23.0000000' AS DateTime2), 1, CAST(N'2021-07-12T16:53:23.0000000' AS DateTime2), 1, 0, 1)
GO
SET IDENTITY_INSERT [dbo].[Users] OFF
GO
/****** Object:  Index [IX_ProjectsTeams]    Script Date: 7/13/2021 2:18:15 PM ******/
CREATE NONCLUSTERED INDEX [IX_ProjectsTeams] ON [dbo].[ProjectsTeams]
(
	[ProjectId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Projects] ADD  CONSTRAINT [DF_Projects_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Projects] ADD  CONSTRAINT [DF_Projects_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[Projects] ADD  CONSTRAINT [DF_Projects_isDeleted]  DEFAULT ((0)) FOR [isDeleted]
GO
ALTER TABLE [dbo].[Tasks] ADD  CONSTRAINT [DF_Tasks_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Tasks] ADD  CONSTRAINT [DF_Tasks_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[Tasks] ADD  CONSTRAINT [DF_Tasks_isDeleted]  DEFAULT ((0)) FOR [isDeleted]
GO
ALTER TABLE [dbo].[Teams] ADD  CONSTRAINT [DF_Teams_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Teams] ADD  CONSTRAINT [DF_Teams_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[Teams] ADD  CONSTRAINT [DF_Teams_isDeleted]  DEFAULT ((0)) FOR [isDeleted]
GO
ALTER TABLE [dbo].[Users] ADD  CONSTRAINT [DF_Users_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Users] ADD  CONSTRAINT [DF_Users_DateOfLastChange]  DEFAULT (getdate()) FOR [DateOfLastChange]
GO
ALTER TABLE [dbo].[Users] ADD  CONSTRAINT [DF_Users_isDeleted]  DEFAULT ((0)) FOR [isDeleted]
GO
ALTER TABLE [dbo].[WorkLog] ADD  CONSTRAINT [DF_WorkLog_Date]  DEFAULT (getdate()) FOR [Date]
GO
ALTER TABLE [dbo].[WorkLog] ADD  CONSTRAINT [DF_WorkLog_isDeleted]  DEFAULT ((0)) FOR [isDeleted]
GO
ALTER TABLE [dbo].[Projects]  WITH CHECK ADD  CONSTRAINT [FK_Projects_Users] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Projects] CHECK CONSTRAINT [FK_Projects_Users]
GO
ALTER TABLE [dbo].[ProjectsTeams]  WITH CHECK ADD  CONSTRAINT [FK_ProjectsTeams_Projects] FOREIGN KEY([ProjectId])
REFERENCES [dbo].[Projects] ([Id])
GO
ALTER TABLE [dbo].[ProjectsTeams] CHECK CONSTRAINT [FK_ProjectsTeams_Projects]
GO
ALTER TABLE [dbo].[ProjectsTeams]  WITH CHECK ADD  CONSTRAINT [FK_ProjectsTeams_Teams] FOREIGN KEY([TeamId])
REFERENCES [dbo].[Teams] ([Id])
GO
ALTER TABLE [dbo].[ProjectsTeams] CHECK CONSTRAINT [FK_ProjectsTeams_Teams]
GO
ALTER TABLE [dbo].[Tasks]  WITH CHECK ADD  CONSTRAINT [FK_Tasks_Projects] FOREIGN KEY([ProjectId])
REFERENCES [dbo].[Projects] ([Id])
GO
ALTER TABLE [dbo].[Tasks] CHECK CONSTRAINT [FK_Tasks_Projects]
GO
ALTER TABLE [dbo].[Tasks]  WITH CHECK ADD  CONSTRAINT [FK_Tasks_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Tasks] CHECK CONSTRAINT [FK_Tasks_Users]
GO
ALTER TABLE [dbo].[Tasks]  WITH CHECK ADD  CONSTRAINT [FK_Tasks_Users1] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Tasks] CHECK CONSTRAINT [FK_Tasks_Users1]
GO
ALTER TABLE [dbo].[Teams]  WITH CHECK ADD  CONSTRAINT [FK_Teams_Users] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Teams] CHECK CONSTRAINT [FK_Teams_Users]
GO
ALTER TABLE [dbo].[Users]  WITH CHECK ADD  CONSTRAINT [FK_Users_Users] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Users] CHECK CONSTRAINT [FK_Users_Users]
GO
ALTER TABLE [dbo].[Users]  WITH CHECK ADD  CONSTRAINT [FK_Users_Users_Creator] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Users] CHECK CONSTRAINT [FK_Users_Users_Creator]
GO
ALTER TABLE [dbo].[UsersTeams]  WITH CHECK ADD  CONSTRAINT [FK_UsersTeams_Teams] FOREIGN KEY([TeamId])
REFERENCES [dbo].[Teams] ([Id])
GO
ALTER TABLE [dbo].[UsersTeams] CHECK CONSTRAINT [FK_UsersTeams_Teams]
GO
ALTER TABLE [dbo].[UsersTeams]  WITH CHECK ADD  CONSTRAINT [FK_UsersTeams_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[UsersTeams] CHECK CONSTRAINT [FK_UsersTeams_Users]
GO
ALTER TABLE [dbo].[WorkLog]  WITH CHECK ADD  CONSTRAINT [FK_WorkLog_Tasks] FOREIGN KEY([TaskId])
REFERENCES [dbo].[Tasks] ([Id])
GO
ALTER TABLE [dbo].[WorkLog] CHECK CONSTRAINT [FK_WorkLog_Tasks]
GO
ALTER TABLE [dbo].[WorkLog]  WITH CHECK ADD  CONSTRAINT [FK_WorkLog_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[WorkLog] CHECK CONSTRAINT [FK_WorkLog_Users]
GO
ALTER TABLE [dbo].[WorkLog]  WITH CHECK ADD  CONSTRAINT [FK_WorkLog_Users1] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[WorkLog] CHECK CONSTRAINT [FK_WorkLog_Users1]
GO
USE [master]
GO
ALTER DATABASE [ManagementSystemProject] SET  READ_WRITE 
GO
